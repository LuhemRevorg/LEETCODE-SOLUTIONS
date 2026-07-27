class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> stck;
        vector<int> ret(temperatures.size());

        for (int i = 0; i < temperatures.size(); ++i) {

            while(!stck.empty() && stck.top().first < temperatures[i]) {
                    ret[stck.top().second] = i - stck.top().second;
                    stck.pop();
            }
            stck.push({temperatures[i], i});
        }
        return ret;
    }
};
