class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> state(numCourses, 0);
        std::vector<std::vector<int>> adj(numCourses);
        for (auto& p : prerequisites)
            adj[p[0]].push_back(p[1]);

        
        std::function<bool(int)> dfs = [&](int curr) -> bool {
            if (state[curr] == 1) return false;
            if (state[curr] == 2) return true;

            state[curr] = 1;
            for (auto i : adj[curr]) if (!dfs(i)) return false;
            state[curr] = 2;
            return true;
        };

        for (int course = 0; course < numCourses; ++course) if(!dfs(course)) return false;
        return true;
    }
};
