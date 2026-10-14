class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1;

        while(true) {
            int num1 = numbers[start], num2 = numbers[end]; 
            if (num1+num2 == target) return {start+1, end+1};
            else if (num1+num2>target) --end;
            else ++start;
        }
        return {};
    }
};
