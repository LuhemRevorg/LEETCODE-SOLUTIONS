class MyCalendar {
    // end time, start time
    std::map<int, int> store;
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        if (store.size() == 0) {
            store[endTime] = startTime;
            return true;
        }
        auto it = store.upper_bound(endTime);
        if (it != store.end() && it->second < endTime) return false;

        if (it != store.begin()) {
            --it;
            if (it->first > startTime) return false;
        }

        store[endTime] = startTime;

        return true;


    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
