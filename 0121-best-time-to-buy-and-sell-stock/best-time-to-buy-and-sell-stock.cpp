class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int price = 0;
       int max = 0;
       int min = 10001;

       for (int i = 0; i < prices.size(); ++i) {
            if (prices.at(i) < min) {
                min = prices.at(i);
            }
            if (price < prices.at(i) - min) {
                price = prices.at(i) - min;
            }
       }

       return price;
    }
};
