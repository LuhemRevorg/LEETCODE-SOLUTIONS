class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;    
        vector<int> curr;
        int sum = 0;
        size_t size = candidates.size();

        auto backtrack = [&](this auto& self, size_t idx) {
            if (sum > target) return;
            if (sum == target && idx == size) {result.emplace_back(curr); return;}
            if (idx == size) return;

            curr.push_back(candidates[idx]);
            sum += candidates[idx];
            self(idx);
            sum -= candidates[idx];
            curr.pop_back();

            self(idx+1);
        
        };

        backtrack(0);
        return result;

    }
};
