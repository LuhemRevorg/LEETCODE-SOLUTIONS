class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<unsigned long, int>, std::vector<std::pair<unsigned long, int>>, std::greater<std::pair<unsigned long, int>>> store;
        std::vector<vector<int>> ret(k);
        for (int i = 0; i < points.size(); ++i) {
            unsigned long distance = (points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            store.push({distance, i});
        }
        for (int j = 0; j < k ; ++j) {
            ret[j]=points[store.top().second]; store.pop();
        }
        return ret;
    }
};
