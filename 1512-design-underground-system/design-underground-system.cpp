class UndergroundSystem {
    // start, end

    struct PairHash {
        template <class T1, class T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            auto hash1 = std::hash<T1>{}(p.first);
            auto hash2 = std::hash<T2>{}(p.second);
            
            // A standard way to combine hashes (similar to boost::hash_combine)
            return hash1 ^ (hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2));
        }
    };
    std::unordered_map<std::pair<string, string>, std::pair<int, int>, PairHash> time_tracker;
    std::unordered_map<int, std::pair<std::string, int>> id_tracker;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        id_tracker[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto &initial = id_tracker[id];
        auto it = time_tracker.find({initial.first, stationName});
        if (it == time_tracker.end()) {
            time_tracker[{initial.first, stationName}] = {t - initial.second, 1};
        } else {
            it->second.first += t - initial.second;
            ++it->second.second; 
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto &val = time_tracker[{startStation, endStation}];
        return (double)val.first / (double)val.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
