class Solution {
    std::unordered_map<int, int> store;
public:
    int climbStairs(int n) {
        if (store.contains(n)) return store[n];
        store[1] = 1;
        store[2] = 2;

        for (int i = 3; i <= n; ++i) {
            store[i] = store[i-1] + store[i-2];
        }

        return store[n];
    }
};
