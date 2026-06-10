class Solution:

    def commonPrefix(self, str1, str2):
        s = ""
        for i in range(min(len(str1), len(str2))):
            if str1[i] == str2[i]:
                s += str1[i]
            else:
                break
        return s


    def longestCommonPrefix(self, strs: List[str]) -> str:
        s = strs[0]
        for i in range(1, len(strs)):
            s = self.commonPrefix(s, strs[i])
            if s == "":
                break
        
        return s
