class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<int> spd(target, -1);
        for (int i = 0; i < n; ++i) spd[position[i]] = speed[i];

        stack<double> stck;
        for (int p = target - 1; p >= 0; --p) {   // closest to target first
            if (spd[p] < 0) continue;
            double t = double(target - p) / spd[p];
            if (stck.empty() || t > stck.top()) stck.push(t);
            // else: t <= top, this car catches the fleet ahead — absorbed
        }
        return stck.size();
    }
};
