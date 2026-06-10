class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        val = sum(nums[::2])
       
        return val
