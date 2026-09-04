class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        std::vector<int> combos(amount+1, 100001);
        combos[0] = 0;
        for(int i = 0; i <= amount; ++i) {
            for(auto coin : coins) {
                if ((long)coin + i <= amount) {
                    combos[i+coin] = std::min(combos[i+coin], combos[i] + 1);
                }
            }
        }

        if (combos.back() == 100001) return -1;
        return combos.back();

    }
};
