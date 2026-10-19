class Solution:
    def arrayNesting(self, nums: list[int]) -> int:
        
        memo = {}
        mx = 0
        for i in range(len(nums)):
            if i in memo:
                continue
            cycle = []
            j = i
            while j not in memo and (not cycle or j != i):
                cycle.append(j)
                j = nums[j]
            for k in cycle:
                memo[k] = len(cycle)
            mx = max(mx, len(cycle))
        return mx
