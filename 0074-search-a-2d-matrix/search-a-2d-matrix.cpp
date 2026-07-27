class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = matrix.size();

        while(end > start) {
            int check = (start+end)/2;
            if(matrix[check][0]==target) return true;
            else if (matrix[check][0]>target) end = check;
            else if (start==check)break;
            else start=check;
        }
        
        int row=start;
        start=0;
        end=matrix[0].size();

        while(end > start) {
            int check = (start+end)/2;
            if(matrix[row][check]==target) return true;
            else if (matrix[row][check]>target) end = check;
            else if (start==check)break;
            else start=check;
        }
        return false;
    }
};
