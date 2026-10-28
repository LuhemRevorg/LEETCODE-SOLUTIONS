class Solution {
public:
    int specialArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        size_t start = 0, end = nums.size();

        while(start <= end) {
            size_t mid = start + (end-start)/2;
            size_t it = nums.end() - std::lower_bound(nums.begin(), nums.end(), mid) ;
            if (it == mid) return mid;
            else if (it > mid) start=mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
};
