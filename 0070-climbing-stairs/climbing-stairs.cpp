class Solution {
    std::vector<int> steps;
    int max;
public:
    Solution() : steps(46, 0) {
        steps[1] = 1; // 1 step -> 1 way
        steps[2] = 2; // 2 steps -> 2 ways
    }

    int climbStairs(int n) {
        if (n <= 2) return n;
        
        if (steps[n] != 0) return steps[n];

        for (int i = 3; i <= n; ++i) {
            if (steps[i] == 0) {
                steps[i] = steps[i - 1] + steps[i - 2];
            }
        }

        return steps[n];
    }
};
