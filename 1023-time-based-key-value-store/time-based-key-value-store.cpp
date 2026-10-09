class TimeMap {
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto ans = std::upper_bound(store[key].begin(), store[key].end(), timestamp, 
            [](int target_ts, const std::pair<int, std::string>& pair) {
                return target_ts < pair.first;
            });
        if (ans != store[key].begin()) {
            return (--ans)->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
