class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;    
        vector<int> curr;
        int sum = 0;
        size_t size = candidates.size();
        std::sort(candidates.begin(), candidates.end());

        auto backtrack = [&](this auto& self, size_t idx) {
            if (sum > target) return;
            if (sum == target && idx == size) {result.emplace_back(curr); return;}
            if (idx == size) return;

            int num = candidates[idx];
            
            curr.push_back(num);
            sum += num;
            
            self(idx+1);
           
            sum -= num;
            curr.pop_back();

            size_t next = idx;
            while (next < size && candidates[next] == num) ++next;
            self(next);
            
        };

        backtrack(0);
        return result;
    }
};
