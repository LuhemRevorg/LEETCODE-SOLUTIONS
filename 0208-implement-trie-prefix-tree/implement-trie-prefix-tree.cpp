class Trie {
    Trie* children[26] = {};
    bool isWord = false;

    // Walk down the trie; return the node at the end of s, or nullptr
    const Trie* find(const string& s) const {
        const Trie* node = this;
        for (char c : s) {
            node = node->children[c - 'a'];
            if (!node) return nullptr;
        }
        return node;
    }

public:
    Trie() = default;
    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    void insert(const string& word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new Trie();
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }

    bool search(const string& word) const {
        const Trie* node = find(word);
        return node && node->isWord;
    }

    bool startsWith(const string& prefix) const {
        return find(prefix) != nullptr;
    }

    ~Trie() {
        for (Trie* child : children) delete child;
    }
};
