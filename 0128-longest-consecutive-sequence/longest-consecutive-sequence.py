class Solution:
     def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0

        num_set = set(nums)  
        best = 0

        for i in num_set:                    
            if i - 1 not in num_set:         
                length = 1
                while i + length in num_set:
                    length += 1
                best = max(best, length)

        return best
