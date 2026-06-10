class Solution:
    def longestPalindrome(self, s: str) -> int:
        lol = {}

        for i in s:
            if lol.get(i) is None:
                lol[i] = 1
            else:
                lol[i] += 1
        ret = 0
        made_odd = False

        for v in lol.values():
            if v % 2 == 0:
                ret += v
            elif (not made_odd):
                ret += v
                made_odd = True
            else:
                ret += v - 1    
        
        return ret
