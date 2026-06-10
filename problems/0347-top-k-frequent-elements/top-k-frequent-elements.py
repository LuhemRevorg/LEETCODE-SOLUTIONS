class Solution:
    

    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        h = {}
        def findMax():
            max_idx = 0
            max_nos = 0
            for i,j in h.items():
                if max_idx <= j:
                    max_nos = i
                    max_idx = j
            
            h[max_nos] = 0
            return max_nos


        

        for i in nums:
            if i not in h:
                h[i] = 1
            else : h[i]+=1
        ret = []
        while k != 0:
            ret.append(findMax())
            k-=1
        return ret
