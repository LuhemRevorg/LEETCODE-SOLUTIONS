class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        std::unordered_map<string, int> location;
        std::vector<int> og;
        std::vector<char> dead(accounts.size(), 0);

        for (int i = 0; i < accounts.size(); ++i) {
            auto &account = accounts[i];
            std::vector<int> groups;

            for (auto itr = account.begin() + 1; itr < account.end(); ++itr) {
                auto loc = location.find(*itr);
                if (loc != location.end() &&
                    std::find(groups.begin(), groups.end(), loc->second) == groups.end())
                    groups.push_back(loc->second);
            }

            if (groups.empty()) {
                og.push_back(i);
                for (auto itr = account.begin() + 1; itr < account.end(); ++itr)
                    location[*itr] = i;
            } else {
                int find_account = *std::max_element(groups.begin(), groups.end(),
                    [&](int a, int b) { return accounts[a].size() < accounts[b].size(); });

                for (int g : groups) {
                    if (g == find_account) continue;
                    for (auto itr = accounts[g].begin() + 1; itr < accounts[g].end(); ++itr) {
                        location[*itr] = find_account;
                        accounts[find_account].emplace_back(std::move(*itr));
                    }
                    accounts[g].resize(1);
                    dead[g] = 1;                                   // fix 1
                }

                for (auto itr = account.begin() + 1; itr < account.end(); ++itr) {
                    if (!location.contains(*itr)) {
                        accounts[find_account].emplace_back(*itr);
                        location[*itr] = find_account;
                    }
                }
            }
        }

        std::vector<vector<string>> ret;
        for (int idx : og) {
            if (dead[idx]) continue;
            auto &acc = accounts[idx];
            std::sort(acc.begin() + 1, acc.end());
            acc.erase(std::unique(acc.begin() + 1, acc.end()), acc.end());  // fix 2
            ret.push_back(std::move(acc));                                // move, don't copy
        }
        return ret;
    }
};
