class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> freq{{0, 1}};  // empty prefix
    int sum = 0, count = 0;
    for (int x : nums) {
        sum += x;
        if (auto it = freq.find(sum - k); it != freq.end())
            count += it->second;  // every earlier prefix equal to sum - k starts a valid subarray
        ++freq[sum];  // insert after the lookup, so a prefix can't pair with itself
    }
    return count;
}
};
