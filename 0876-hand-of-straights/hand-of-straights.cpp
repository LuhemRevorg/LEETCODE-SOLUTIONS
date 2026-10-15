class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) return false;

    std::map<int, int> count;
    for (int x : hand) ++count[x];

        for (auto it = count.begin(); it != count.end(); ++it) {
            int c = it->second;
            if (c == 0) continue;

            auto nxt = it;
            for (int k = 1; k < groupSize; ++k) {
                ++nxt;
                if (nxt == count.end() || nxt->first != it->first + k || nxt->second < c)
                    return false;
                nxt->second -= c;
            }
        }
    return true;
    }
};
