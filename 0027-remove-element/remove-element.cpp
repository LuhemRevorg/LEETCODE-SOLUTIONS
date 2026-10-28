class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
            size_t start = 0, end = nums.size();
            while (start < end) {
                if (nums[start] == val) nums[start] = nums[--end];
                else ++start;
            }
            return end;

    }
};
