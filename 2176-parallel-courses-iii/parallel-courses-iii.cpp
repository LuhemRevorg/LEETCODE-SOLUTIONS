class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> lol(n+1); // maintains relations 
        vector<int> inNos(n+1,0);

        queue<int> q;

        vector<int> dp(n + 1, 0);

        for (auto &relation : relations) {
            lol[relation[0]].push_back(relation[1]);
            ++inNos[relation[1]];
        }

        for (int i = 1; i < inNos.size(); ++i) if(inNos[i]==0) {q.push(i); dp[i] = time[i-1];}

        while(!q.empty()) {
            int curr = q.front(); q.pop();

            for (auto &rels : lol[curr]) {

                dp[rels] = std::max(dp[rels], time[rels-1] + dp[curr]);
            
                if(--inNos[rels] == 0) q.push(rels);
            }
        }

        return *max_element(dp.begin() + 1, dp.end());

    }
};
