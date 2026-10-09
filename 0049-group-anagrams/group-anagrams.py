class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}

        for s in strs:
            val = "".join(sorted(s))
            if val in mp:
                mp[val].append(s)
            else:
                mp[val] = [s]

        return list(mp.values())
