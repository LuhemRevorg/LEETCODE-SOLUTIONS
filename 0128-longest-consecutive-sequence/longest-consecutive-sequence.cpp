class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> store;   // 0 = unvisited; at a run start = run length
        store.reserve(nums.size());
        for (int x : nums) store[x] = 0;

        int best = 0;
        for (int start : nums) {
            auto startIt = store.find(start);
            if (startIt->second != 0) continue;       // already covered

            int curr = 0;
            long long val = start;                     // avoids ++INT_MAX overflow
            auto it = startIt;
            while (it != store.end()) {
                if (it->second != 0) {                 // hit an earlier run's start
                    curr += it->second;
                    break;
                }
                it->second = ++curr;                   // mark visited
                it = (++val > INT_MAX) ? store.end() : store.find((int)val);
            }
            startIt->second = curr;                    // full length, written once
            best = max(best, curr);
        }
        return best;
    }
};
