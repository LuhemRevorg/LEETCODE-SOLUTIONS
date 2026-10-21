class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        std::sort(startTime.begin(), startTime.end()); // 1,2,3
        std::sort(endTime.begin(), endTime.end()); // 2,3,7

        int nos_started = std::upper_bound(startTime.begin(), startTime.end(), queryTime) - startTime.begin();
        int nos_ended = std::lower_bound(endTime.begin(), endTime.end(), queryTime) - endTime.begin();
        
        return nos_started - nos_ended;
    }
};
