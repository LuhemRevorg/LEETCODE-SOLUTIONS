class MinStack {
    std::vector<std::pair<int, int>> stck;
    int min;
public:
    MinStack(): min{INT_MAX} {}
    
    void push(int value) {
        min = std::min(min, value);
        stck.emplace_back(value, min);
    }
    void pop() {
        stck.pop_back();
        if (!stck.empty()) min = stck.back().second;
        else min = INT_MAX;
    }   
    
    int top() {
        return stck.back().first;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
