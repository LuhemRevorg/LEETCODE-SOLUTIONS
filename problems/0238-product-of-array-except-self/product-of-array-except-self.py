class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        pre = []
        post = [0] * len(nums)
        x = 1
        for i in nums:
            x*=i
            pre.append(x)
        x=1
        t=len(nums)  - 1
        for i in reversed(nums):
            x=x*i
            post[t] = x
            t-=1
        ret = []
        ret.append(post[1])
        for i in range(1,len(nums)-1):
            ret.append(pre[i-1]*post[i+1])
        ret.append(pre[-2])
        return ret
