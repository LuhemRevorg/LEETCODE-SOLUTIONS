class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        std::unordered_map<int, int> busyness;
        std::set<int> free;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<>> busy;

        for (int i = 0; i < k; ++i) free.insert(i);
        int max_busy = 0;

        for (auto itr = 0; itr < arrival.size(); ++itr) {

            while(!busy.empty() && busy.top().first <= arrival[itr]) {free.insert(busy.top().second); busy.pop();}

            
            if (free.empty()) continue;
            
            auto free_server = free.lower_bound(itr % k);            

            if (free_server == free.end()) free_server = free.begin();

            auto &v = busyness[*free_server]; ++v;
            max_busy = std::max(v, max_busy);
            busy.push({load[itr] + arrival[itr], *free_server});

            free.erase(free_server);

        }

        std::vector<int> ret;

        for (auto [server_id, count] : busyness) {
            if (count == max_busy) ret.emplace_back(server_id);
        }

        return ret;

    }
};
