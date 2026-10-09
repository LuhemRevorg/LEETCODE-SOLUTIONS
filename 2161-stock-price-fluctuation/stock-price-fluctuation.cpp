class StockPrice {
    std::unordered_map<int, int> store;
    std::priority_queue<std::pair<int,int>> maxHeap;
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> minHeap;
    int latest = 0;

public:
    void update(int timestamp, int price) {
        store[timestamp] = price;
        latest = std::max(latest, timestamp);
        maxHeap.push({price, timestamp});
        minHeap.push({price, timestamp});
    }

    int current() { return store[latest]; }

    int maximum() {
        while (store[maxHeap.top().second] != maxHeap.top().first) maxHeap.pop();
        return maxHeap.top().first;
    }

    int minimum() {
        while (store[minHeap.top().second] != minHeap.top().first) minHeap.pop();
        return minHeap.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
