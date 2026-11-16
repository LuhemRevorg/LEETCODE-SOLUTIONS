class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        auto it = std::min_element(tasks.begin(), tasks.end(), [](const std::vector<int> &t1, const std::vector<int> &t2) {return t1[0] + t1[1] < t2[0] + t2[1];});
        return (*it)[0] + (*it)[1];
    }
};
