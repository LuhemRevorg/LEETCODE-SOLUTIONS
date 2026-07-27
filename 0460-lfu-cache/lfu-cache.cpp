using namespace std;

class LFUCache {
    struct Node {
        int key, value, freq;
        Node* prev;
        Node* next;
        Node(int k, int v, int f) : key(k), value(v), freq(f), prev(nullptr), next(nullptr) {}
    };

    struct DList {
        Node* head;
        Node* tail;
        int size = 0;
        DList() {
            head = new Node(0, 0, 0);
            tail = new Node(0, 0, 0);
            head->next = tail;
            tail->prev = head;
        }
        ~DList() {
            Node* cur = head;
            while (cur) {
                Node* nxt = cur->next;
                delete cur;
                cur = nxt;
            }
        }
        void pushFront(Node* n) {
            n->next = head->next;
            n->prev = head;
            head->next->prev = n;
            head->next = n;
            ++size;
        }
        void remove(Node* n) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            n->prev = n->next = nullptr;
            --size;
        }
        Node* popBack() {
            if (size == 0) return nullptr;
            Node* n = tail->prev;
            remove(n);
            return n;
        }
        bool empty() const { return size == 0; }
    };

    int capacity;
    int size;
    int minFreq;
    unordered_map<int, Node*> keyTable;      // key -> Node*
    unordered_map<int, DList*> freqTable;    // freq -> bucket

    // Move an existing node up to the next frequency bucket
    void touch(Node* node) {
        int f = node->freq;
        DList* oldBucket = freqTable[f];
        oldBucket->remove(node);
        if (oldBucket->empty()) {
            delete oldBucket;
            freqTable.erase(f);
            if (minFreq == f) ++minFreq;
        }

        node->freq = f + 1;
        if (!freqTable.count(node->freq)) freqTable[node->freq] = new DList();
        freqTable[node->freq]->pushFront(node);
    }

public:
    LFUCache(int capacity) : capacity(capacity), size(0), minFreq(0) {}

    ~LFUCache() {
        for (auto& [f, bucket] : freqTable) delete bucket;
    }

    int get(int key) {
        auto it = keyTable.find(key);
        if (it == keyTable.end()) return -1;
        Node* node = it->second;
        touch(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        auto it = keyTable.find(key);
        if (it != keyTable.end()) {
            Node* node = it->second;
            node->value = value;
            touch(node);
            return;
        }

        if (size == capacity) {
            DList* minBucket = freqTable[minFreq];
            Node* victim = minBucket->popBack();
            keyTable.erase(victim->key);
            delete victim;
            --size;
            if (minBucket->empty()) {
                delete minBucket;
                freqTable.erase(minFreq);
            }
        }

        Node* node = new Node(key, value, 1);
        keyTable[key] = node;
        if (!freqTable.count(1)) freqTable[1] = new DList();
        freqTable[1]->pushFront(node);
        minFreq = 1;
        ++size;
    }
};
