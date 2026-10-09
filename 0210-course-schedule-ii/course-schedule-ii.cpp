class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> visited(numCourses, 0);
        std::vector<std::vector<int>> neighbors(numCourses);

        for (auto i : prerequisites) {
            neighbors[i[1]].push_back(i[0]);
        }

        std::vector<int> ret;

        auto dfs = [&](auto &self, int node) -> bool {
            if (visited[node]==1) return true;
            if (visited[node]==2) return false;
            if (visited[node] == 0) {
                visited[node] = 1; 
                
                    for (auto n : neighbors[node]) {
                        if (self(self, n)) return true;
                }
                visited[node] = 2;
                ret.push_back(node);
            }
            return false;
        };

        for (int i = 0; i < numCourses; ++i) {if (dfs(dfs, i)) return {};}

        std::reverse(ret.begin(),ret.end());
        return ret;

    }
};
