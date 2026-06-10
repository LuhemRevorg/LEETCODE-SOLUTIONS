class Solution {
public:

    int helper(int start,int end,vector<int>& citations) {
        if (start >= end) {
            return start;
        }

        int index = (end-start)/2 + start;
        
        if (index + 1 > citations[index]){
            return helper(start, index, citations);
        } else {
            return helper(index + 1, end, citations);
        }
    }

    int hIndex(vector<int>& citations) {
        std::sort(citations.rbegin(), citations.rend());
        return helper(0, citations.size(), citations);
    }
};
