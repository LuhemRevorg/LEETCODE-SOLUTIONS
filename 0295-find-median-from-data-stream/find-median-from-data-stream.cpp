class MedianFinder {

    std::priority_queue<int> maxHeap;
    std::priority_queue<int, vector<int>, std::greater<int>> minHeap;

public:

    MedianFinder(){}
    
    void addNum(int num) {
        maxHeap.push(num);
        if(maxHeap.size() > minHeap.size()) {minHeap.push(maxHeap.top()); maxHeap.pop();}
        if(minHeap.size() > maxHeap.size()) {maxHeap.push(minHeap.top()); minHeap.pop();}
    }
    
    double findMedian() {
        
        if ((minHeap.size() + maxHeap.size()) % 2==0) {return ((double)minHeap.top() + (double)maxHeap.top())/2;}
        return (double)maxHeap.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
