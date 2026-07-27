class Solution {

    class Order {
        
        int price;
        int amount;


        friend Solution;
        public:
            Order(int price, int amount):price{price}, amount{amount} {}
    };

    struct BuyCompare { // max-heap: highest price on top
        bool operator()(const Order& a, const Order& b) const {
            return a.price < b.price;
        }
    };

    struct SellCompare { // min-heap: lowest price on top
        bool operator()(const Order& a, const Order& b) const {
            return a.price > b.price;
        }
    };






public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    std::priority_queue<Order, std::vector<Order>, BuyCompare> buyBacklog;
    std::priority_queue<Order, std::vector<Order>, SellCompare> sellBacklog;

    for (auto &order : orders) {
        Order curr = Order(order[0], order[1]);
        if (order[2] == 0) { // Buy order
            while (curr.amount > 0 && !sellBacklog.empty() && sellBacklog.top().price <= curr.price) {
                if (sellBacklog.top().amount > curr.amount) {
                    const_cast<Order&>(sellBacklog.top()).amount -= curr.amount;
                    curr.amount = 0;
                } else {
                    curr.amount -= sellBacklog.top().amount;
                    sellBacklog.pop();
                }
            }
            if (curr.amount > 0) buyBacklog.push(curr);
        } else { // Sell order
            while (curr.amount > 0 && !buyBacklog.empty() && buyBacklog.top().price >= curr.price) {
                if (buyBacklog.top().amount > curr.amount) {
                    const_cast<Order&>(buyBacklog.top()).amount -= curr.amount;
                    curr.amount = 0;
                } else {
                    curr.amount -= buyBacklog.top().amount;
                    buyBacklog.pop();
                }
            }
            if (curr.amount > 0) sellBacklog.push(curr);
        }
    }

    long long amount = 0;
    while (!sellBacklog.empty()) { amount += sellBacklog.top().amount; sellBacklog.pop(); }
    while (!buyBacklog.empty())  { amount += buyBacklog.top().amount;  buyBacklog.pop();  }

    return static_cast<int>(amount % 1000000007);
}

};
