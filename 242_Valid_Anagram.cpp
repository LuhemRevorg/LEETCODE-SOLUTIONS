bool isAnagram(string s, string t) {
        unordered_map<char, int> s_storage;
        unordered_map<char, int> t_storage;
        
        for (auto i : s) {
            ++s_storage[i];
        }

        for (auto i : t) {
            ++t_storage[i];
        }
        
        for (auto i : s) {
            if (s_storage[i]!=t_storage[i]) return false;
        }
        for (auto i : t) {
            if (s_storage[i]!=t_storage[i]) return false;
        }

        return true;

    }