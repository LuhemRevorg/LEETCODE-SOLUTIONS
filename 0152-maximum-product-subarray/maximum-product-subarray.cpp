class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int min = nums[0], max = nums[0], lol = nums[0];

        for (auto i = nums.begin()+1; i != nums.end(); ++i) {
            int val = *i;
            int tmp = std::max({val, val * max, val * min});
            min=std::min({val, val*max, val*min});        
            max = tmp;
            lol=std::max(max, lol);
        }

        return lol;
    }
};
