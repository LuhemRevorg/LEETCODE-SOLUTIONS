class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<vector<int>> result;
        std::vector<int> path;
        auto backtrack = [&](this auto &self, int idx) {
             
            if (idx == nums.size()) {result.emplace_back(path); return;}
                
            path.push_back(nums[idx]);
            self(idx+1);
            path.pop_back();
            
            self(idx+1);

        };

        backtrack(0);

        return result;
    }
};
