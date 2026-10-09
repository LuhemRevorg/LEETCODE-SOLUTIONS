class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> heap(stones.begin(), stones.end());
        
        while(heap.size()>1) {
            int num1 = heap.top(); heap.pop(); int num2 = heap.top(); heap.pop();
            heap.push(std::abs(num1-num2));
        }

        return heap.top();
    }
};
