class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        if (nums.size()==2) {return std::min(nums[0], nums[1]);}
        while(start < end) {
            int mid = (start+end)/2;
            if(nums[mid-1]>nums[mid]) return nums[mid];
            else if(nums[mid+1]<nums[mid]) return nums[mid+1];
            else if (nums[mid] > nums[start] && nums[mid] > nums[end]) start=mid;
            else if (nums[mid] < nums[start] && nums[mid] < nums[end]) end=mid;
            else if (nums[mid] > nums[start] && nums[mid] < nums[end]) return nums[0];
            else return nums.back();
        }
        return nums[end];
    }
};
