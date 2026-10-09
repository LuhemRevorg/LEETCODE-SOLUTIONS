#include <algorithm>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *std::max_element(piles.begin(), piles.end());

        auto check = [&](int k) -> bool {
            int hours = 0;
            for (auto i : piles) {
                hours += (i + k - 1) / k;;
            }
            return hours<=h;
        };

        while (start < end) {
            int k = (start + end)/2;
            if (check(k)) end =  k;
            else start = k+1;
        }

        return start;
        
    }
};
