class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> dp(hi + 1, 0);           // dp[1] = 0
        for (int x = 2; x <= hi; ++x) {
            long long y = x;
            int steps = 0;
            while (y >= x) {                 // walk until we fall below x
                y = (y & 1) ? 3 * y + 1 : y >> 1;
                ++steps;
            }
            dp[x] = steps + dp[y];           // dp[y] already computed
        }

        priority_queue<pair<int,int>> pq;    // max-heap of (power, value)
        for (int x = lo; x <= hi; ++x) {
            pq.push({dp[x], x});
            if (pq.size() > k) pq.pop();     // drop the largest
        }
        return pq.top().second;
    }
};
