class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size();
        const long long MOD = 1000000007;
        if (n < 5) return 0;

        // pre[i][a][b]  = # subsequences "a then b" within s[0..i-1]
        // suf[i][a][b]  = # subsequences "a then b" within s[i..n-1]
        vector<array<array<int, 10>, 10>> pre(n + 1), suf(n + 1);
        for (auto &m : pre) for (auto &row : m) row.fill(0);
        for (auto &m : suf) for (auto &row : m) row.fill(0);

        // Build prefix table
        {
            array<int, 10> cnt{}; // counts of chars strictly before current index
            for (int i = 0; i < n; ++i) {
                pre[i + 1] = pre[i];
                int c = s[i] - '0';
                for (int a = 0; a < 10; ++a)
                    pre[i + 1][a][c] += cnt[a];
                cnt[c]++;
            }
        }

        // Build suffix table
        {
            array<int, 10> cnt{}; // counts of chars strictly after current index
            for (int i = n - 1; i >= 0; --i) {
                suf[i] = suf[i + 1];
                int c = s[i] - '0';
                for (int b = 0; b < 10; ++b)
                    suf[i][c][b] += cnt[b];
                cnt[c]++;
            }
        }

        long long ans = 0;
        for (int center = 2; center <= n - 3; ++center) {
            for (int a = 0; a < 10; ++a) {
                for (int b = 0; b < 10; ++b) {
                    long long leftCount = pre[center][a][b];
                    if (leftCount == 0) continue;
                    long long rightCount = suf[center + 1][b][a];
                    ans = (ans + leftCount * rightCount) % MOD;
                }
            }
        }

        return (int) ans;
    }
};
