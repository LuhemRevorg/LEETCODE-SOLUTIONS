class Solution {
public:
    int trap(vector<int>& height) {
        size_t left = 0, right = 1;
        size_t n = height.size();
        int total = 0;
        while(right < n) {
            while(right < n && height[right] <= height[left]) ++right; // max till now is left
            if (right == n) {
                int r = (int)n - 1;      
                int l = r - 1;           
                int stop = (int)left;
                while (l >= stop) {
                    while (height[l] < height[r]) --l;
                    int level = height[r];
                    while (r > l) { total += level - height[r]; --r; }
                    --l;
                }
                break;  
            }
            int max = height[left]; 
            while (left < right) {total+= max - height[left]; ++left;}
        }
        return total;
    }
};
