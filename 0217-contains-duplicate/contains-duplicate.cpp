class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> store;
        for (auto i : nums) {
            if (store.contains(i)) return true;
            store.insert(i);
        }
        return false;
    
    }
};
