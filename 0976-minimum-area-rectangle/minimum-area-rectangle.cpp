class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<long long>()((long long)p.first * 40001 + p.second);
        }
    };
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT_MAX;
        std::unordered_set<std::pair<int,int>, PairHash> st;

        for (auto &point : points) st.insert({point[0], point[1]});
        // Check pairwise
        for (auto p1 = st.begin(); p1 != st.end(); ++p1) {
            for (auto p2 = std::next(p1); p2 != st.end(); ++p2) {
                if (p1->first == p2->first || p1->second == p2->second) continue;
                if (st.contains({p1->first, p2->second}) && st.contains({p2->first, p1->second})) ans = min(ans, abs(
                    (p1->first - p2->first) * (p1->second - p2->second) 
                ));
            }
        }
        if (ans == INT_MAX) ans = 0;
        return ans;

    }
};
