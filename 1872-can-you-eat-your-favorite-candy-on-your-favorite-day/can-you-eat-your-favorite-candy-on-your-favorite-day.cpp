class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        size_t total_candies = candiesCount.size();
        std::vector<unsigned long> total(total_candies);
        total[0] = candiesCount[0];
        
        for (int i = 1; i < candiesCount.size(); ++i) total[i] = total[i-1] + candiesCount[i];

        size_t queries_size = queries.size();
        std::vector<bool> ret;

        for (auto &query : queries) {
            unsigned long type = query[0];
            unsigned long day = query[1];
            unsigned long cap = query[2];

            if (total[type] - candiesCount[type] < (day + 1)*cap && total[type] >= (day + 1)) ret.push_back(true);
            else ret.push_back(false);
        }

        return ret;
    }
};
