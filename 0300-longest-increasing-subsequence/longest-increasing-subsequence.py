class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        table = [1 for _ in range(len(nums))]

        for i in range(len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    table[i] = max(1, table[j] + 1, table[i])
        
        return max(table)
