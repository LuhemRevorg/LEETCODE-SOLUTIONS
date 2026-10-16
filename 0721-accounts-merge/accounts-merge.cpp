class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        std::map<string, string> relation;
        std::unordered_map<string, string> mail_to_name;

        auto find = [&](string mail) -> string {                       // FIX: explicit return type
            auto it = relation.find(mail);
            if (it == relation.end()) return "";
            while (relation[mail] != mail) mail = relation[mail];      // FIX: walk up to the root
            return mail;
        };

        for (auto &account : accounts) {
            string name = account[0];                                  // FIX: string, not int
            string parent = account[1];
            for (int i = 1; i < account.size(); ++i) {                 // FIX: start at 1, not 2
                string f = find(account[i]);
                if (f != "") parent = f; 
            }
            relation[parent] = parent;
            mail_to_name[parent] = name;

            for (int i = 1; i < account.size(); ++i) {                 // FIX: start at 1
                string f = find(account[i]);
                relation[f == "" ? account[i] : f] = parent;           // FIX: re-point the old root, merging its whole group
            }
        }

        std::vector<std::vector<string>> ret;
        std::unordered_map<string, int> idx_map;

        for (auto &[key, val] : relation) {
            string root = find(key);                                   // FIX: group by root, not direct parent
            if (idx_map.contains(root)) {                              // FIX: was map_idx
                ret[idx_map[root]].emplace_back(key);                  // FIX: was ret[i]
            } else {
                idx_map[root] = ret.size();
                ret.push_back({mail_to_name[root], key});              // FIX: one row of {name, email}
            }
        }

        return ret;

    }
};
