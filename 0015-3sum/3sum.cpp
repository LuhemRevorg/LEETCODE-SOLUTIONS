class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        std::vector<std::vector<int>> ret;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n-1, target = -nums[i];
            while(j<=k) {
                if (nums[j]+nums[k]==target && j!=k) {ret.push_back({nums[i], nums[j], nums[k]}); 
                    while (j < k && nums[j] == nums[j + 1]) ++j;
                    while (j < k && nums[k] == nums[k - 1]) --k;
                    ++j;
                    --k;
                }
                else if (nums[j]+nums[k]>target) --k;
                else ++j;
            }
        }
        return ret;
    }
};
