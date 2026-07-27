class RandomizedSet {
    unordered_map<int, int> idx;  // val -> index in nums
    vector<int> nums;

    
public:
    bool insert(int val) {
        if (idx.count(val)) return false;
        idx[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!idx.count(val)) return false;
        int i = idx[val];
        int last = nums.back();
        nums[i] = last;
        idx[last] = i;
        nums.pop_back();
        idx.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
