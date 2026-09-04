class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> freq(26, 0);
        int start = 0;
        int max_freq = 0;
        int max_len = 0;

        for (int end = 0; end < s.length(); ++end) {
            freq[s[end] - 'A']++;
            max_freq = std::max(max_freq, freq[s[end] - 'A']);

            while ((end - start + 1) - max_freq > k) {
                freq[s[start] - 'A']--;
                start++;
            }

            
            max_len = std::max(max_len, end - start + 1);
        }

        return max_len;
    }
};
