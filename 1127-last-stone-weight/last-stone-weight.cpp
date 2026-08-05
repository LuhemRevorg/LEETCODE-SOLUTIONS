class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> store(stones.begin(), stones.end());
        
        int rem = store.top(); store.pop();

        while(!store.empty()) {
            rem -= store.top(); store.pop();
            if (!(rem==0)) store.push(rem);
            else if (store.empty()) return 0;
            rem = store.top(); store.pop();
        }

        return rem;

        
    }
};
