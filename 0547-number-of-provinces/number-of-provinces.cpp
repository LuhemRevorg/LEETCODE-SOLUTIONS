class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        std::unordered_map<int, int> parent;

        auto find = [&](int x) {
            if (!parent.count(x)) parent[x] = x;                        // FIX: 0 is a real node, can't be the "missing" sentinel
            while (parent[x] != x) x = parent[x] = parent[parent[x]];   // FIX: actually compress the path
            return x;
        };

        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected.size(); ++j) {
                if (isConnected[i][j] == 1) {
                    int a = find(i), b = find(j);                       // FIX: union the roots
                    parent[a] = b;
                }
            }
        }

        int count = 0;                                                  // FIX: count roots and return
        for (int i = 0; i < isConnected.size(); ++i)
            if (parent[i] == i) ++count;
        return count;


    }
};
