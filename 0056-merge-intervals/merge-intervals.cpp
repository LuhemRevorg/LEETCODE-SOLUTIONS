class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        std::vector<std::vector<int>> ret;
        ret.push_back(intervals[0]);

    
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= ret.back()[1]) {
                ret.back()[1] = std::max(ret.back()[1], intervals[i][1]);
            } else {
                ret.push_back(intervals[i]);
            }
        }

        return ret;
    }
};
