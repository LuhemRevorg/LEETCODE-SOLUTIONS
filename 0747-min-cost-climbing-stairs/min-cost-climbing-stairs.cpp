class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        std::vector<int> store(n+1, 0);
        store[1] = cost[0];
        for (int i = 2; i <= n; ++i) store[i] = std::min(store[i-1], store[i-2]) + cost[i-1];
        return std::min(store[n-1],store.back());
    }
};
