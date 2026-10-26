class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const vector<int> &v1, const vector<int> &v2) {return v1[1] < v2[1];});

        int first = points[0][1];
        int count = 1;
        for (size_t i = 1; i < points.size(); ++i) {
            if (points[i][0] > first) {
                ++count;
                first = points[i][1];
            } 
        }
        return count;
    }
};
