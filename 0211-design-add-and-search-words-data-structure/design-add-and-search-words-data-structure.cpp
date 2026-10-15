class WordDictionary {
    WordDictionary* children[26] = {};
    bool isWord = false;

    bool dfs(const string& w, size_t i) const {
        const WordDictionary* node = this;
        for (; i < w.size(); ++i) {
            if (w[i] == '.') {
                for (const WordDictionary* child : node->children)
                    if (child && child->dfs(w, i + 1)) return true;   // early exit
                return false;
            }
            node = node->children[w[i] - 'a'];
            if (!node) return false;
        }
        return node->isWord;
    }

public:
    WordDictionary() = default;
    WordDictionary(const WordDictionary&) = delete;
    WordDictionary& operator=(const WordDictionary&) = delete;

    void addWord(const string& word) {
        WordDictionary* node = this;
        for (char c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new WordDictionary();
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }

    bool search(const string& word) const {
        return dfs(word, 0);
    }

    ~WordDictionary() {
        for (WordDictionary* child : children) delete child;
    }
};
