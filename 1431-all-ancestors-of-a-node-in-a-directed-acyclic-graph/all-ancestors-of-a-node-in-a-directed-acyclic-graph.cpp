class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n), ans(n);
    for (auto& e : edges) adj[e[0]].push_back(e[1]);

    vector<bool> seen(n);
    auto dfs = [&](this auto& self, int u, int src) -> void {
        for (int v : adj[u]) {
            if (seen[v]) continue;
            seen[v] = true;
            ans[v].push_back(src);
            self(v, src);
        }
    };

    for (int src = 0; src < n; ++src) {
        fill(seen.begin(), seen.end(), false);
        dfs(src, src);
    }
    return ans;
}
};
