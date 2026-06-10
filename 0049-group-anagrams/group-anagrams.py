class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        h = {}

        for i in strs:
            j = ''.join(sorted(i))
            if j in h:
                h[j].append(i)
            else: h[j] = [i]
        
        ret = list(h.values())
        return ret
