class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::vector<int> wow(26, 0);
        for (auto c : tasks) {
            ++wow[c - 'A'];
        }
        int maxCount = *std::max_element(wow.begin(), wow.end());
        int maxCountTasks = std::count(wow.begin(), wow.end(), maxCount);
        return std::max((int)tasks.size(), (maxCount - 1) * (n + 1) + maxCountTasks);
    }
};
