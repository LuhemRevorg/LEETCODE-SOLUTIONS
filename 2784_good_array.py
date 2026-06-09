class Solution:
    def isGood(self, nums: List[int]) -> bool:

        if sum(nums) == (len(nums)-1)*(len(nums) + 2)/2 and len(set(nums)) == len(nums) - 1 and max(nums) == len(nums)-1:
            return True
        
        return False
        