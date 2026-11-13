class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        std::unordered_map<char, int> store;
        for (auto c : magazine) ++store[c];

        for (auto r : ransomNote) {
            auto itr = store.find(r);
            if (itr==store.end() || itr->second == 0) return false;
            --itr->second;
        }
        
        return true;
    }
};
