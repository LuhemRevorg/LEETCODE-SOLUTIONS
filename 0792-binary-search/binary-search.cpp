class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int start = 0;
        int end = len;

        while(end > start) {
            if (nums[(start+end)/2] == target) {
                return (start+end)/2;
            } else if (nums[(start+end)/2] > target) {
                end = (start+end)/2;
            } else if (start == (start+end)/2) {
                break;
            } else start = (start+end)/2;
        }
        return -1;
    }
};
