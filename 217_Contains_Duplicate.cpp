bool containsDuplicate(vector<int>& nums) {
    std::unordered_map<int, int> storage;
    for (auto i : nums) {
        if (storage.find(i) !=storage.end()) return true;
        else storage[i]=1;
    }
    return false;
}