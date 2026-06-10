class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        str_len_left = len(s)
        
        ret = 0
        for i in range(len(s)):
            m = 0
            chars = {}
            if m > str_len_left:
                return ret
            for j in range(i, len(s)):
                if s[j] in chars:
                    break
                else:
                    chars[s[j]] = True
                    m += 1
                
            if m > ret:
                ret = m

            str_len_left -= 1
        return ret
