class Solution:
    def maximumDifference(self, nums: list[int]) -> int:
        ans = -1
        start = 0

        for end in range(1,len(nums)):  
            if nums[end] > nums[start]:
                ans = max(ans, nums[end] - nums[start])
            else:
                start = end
            end+=1
        
        return ans
