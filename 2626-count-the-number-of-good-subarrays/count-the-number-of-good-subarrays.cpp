class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> cnt;
    long long pairs = 0, good = 0;
    int left = 0;
    for (int right = 0; right < n; ++right) {
        pairs += cnt[nums[right]]++;          // adds old count
        while (pairs >= k) {
            good += n - right;                // [left, right..n-1] all good
            pairs -= --cnt[nums[left]];       // removes (count - 1)
            ++left;
        }
    }
    return good;
}
};
