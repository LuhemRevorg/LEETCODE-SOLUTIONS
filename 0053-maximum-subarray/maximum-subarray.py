class Solution:
    def maxLeft(self, nums):
        s = nums[-1]
        ret = nums[-1]
        i = len(nums) - 2
        while i >= 0:
            s += nums[i]
            if s > ret:
                ret = s
            i-=1
        
        return ret
    
    def maxRight(self, nums):
        s = nums[0]
        ret = nums[0]
        i = 1
        while i < len(nums):
            s += nums[i]
            if s > ret:
                ret = s
            i+=1
        
        return ret
    


    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        left = self.maxSubArray(nums[:len(nums)//2])
        right = self.maxSubArray(nums[len(nums)//2:])
        s = self.maxLeft(nums[:len(nums)//2]) + self.maxRight(nums[len(nums)//2:])

        return max([left, right, s])
