class Solution {
public:
    int halveArray(vector<int>& nums) {
        double half = (double)(std::accumulate(nums.begin(), nums.end(), 0.0)) / 2;
        std::priority_queue<double> pq(nums.begin(), nums.end());
        int count = 0;
        while(half > 0) {
            ++count;
            double num = pq.top();
            num /= 2;
            half -= num;
            pq.pop();
            pq.push(num);
        }

        return count;

    }
};
