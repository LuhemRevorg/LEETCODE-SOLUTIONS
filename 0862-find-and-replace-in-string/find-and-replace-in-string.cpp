class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        // index, source, target
        std::vector<std::tuple<int, string, string>> store;
        for (int i = 0; i < indices.size(); ++i) {
            store.emplace_back(indices[i], sources[i], targets[i]);
        }
        std::sort(store.begin(), store.end());

        string result = "";
        int prev = 0;
        for (const auto &item : store) {
            auto index = std::get<0>(item);
            auto &source = std::get<1>(item);
            auto &target = std::get<2>(item);

            if (index < prev) continue;

            result += s.substr(prev, index - prev);

            if (s.substr(index, source.length()) == source) {result+=target; prev = index + source.length();}
            else prev = index;
        }

        result+= s.substr(prev);

        return result;

    }
};
