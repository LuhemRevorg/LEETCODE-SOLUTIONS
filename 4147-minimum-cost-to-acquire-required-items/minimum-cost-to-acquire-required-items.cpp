class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth, n1 = need1, n2 = need2;
        if (c1 > c2) { std::swap(c1, c2); std::swap(n1, n2); }   // now c1 <= c2

        if (cb <= c1) return cb * std::max(n1, n2);              // "both" beats everything
        if (cb <= c2) return cb * n2 + c1 * std::max(0LL, n1 - n2); // over-buy for the pricier side
        if (cb < c1 + c2) {                                      // "both" only for the overlap
            long long m = std::min(n1, n2);
            return cb * m + c1 * (n1 - m) + c2 * (n2 - m);
        }
        return c1 * n1 + c2 * n2;                                // never buy "both"
    }
};
