class Solution {
public:

    class Data {
        int no;
        int idx;
        friend class Solution;

        Data(int no, int idx): no{no}, idx{idx} {}
        public:
            bool operator<(const Data& other) const {
                return no < other.no;
            }
    };


    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::priority_queue<Data> swm;
        std::vector<int> ret;
        int end = k-1;

        for(int i = 0; i < k-1; ++i) {
            swm.push(Data(nums.at(i), i));
        }

        while(end < nums.size()) {
            swm.push(Data(nums.at(end), end));
            while(swm.top().idx > end || swm.top().idx < end-k+1) swm.pop();
            ret.push_back(swm.top().no);
            ++end;
        }

        return ret;

    }
};
