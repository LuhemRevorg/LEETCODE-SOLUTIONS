class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
    // 1. Count frequencies
    unordered_map<string, int> freq;
    for (const string& w : words) freq[w]++;

    // 2. Buckets: index = frequency, value = list of words with that frequency
    int n = words.size();
    vector<vector<string>> buckets(n + 1);
    for (auto& [word, count] : freq) {
        buckets[count].push_back(word);
    }

    // 3. Walk from highest frequency down
    vector<string> result;
    for (int f = n; f >= 1 && result.size() < k; --f) {
        if (buckets[f].empty()) continue;
        sort(buckets[f].begin(), buckets[f].end());   // tie-break: lexicographic
        for (const string& w : buckets[f]) {
            result.push_back(w);
            if (result.size() == k) break;
        }
    }
    return result;
}
};
