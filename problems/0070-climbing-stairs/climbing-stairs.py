class Solution:
    def climbStairs(self, n: int) -> int:
        table = []
        if n == 1:
            return 1
        table.append(1) # 0
        table.append(1) # 1
        table.append(2) # 2
        for i in range(2, n):
            table.append(table[i-1]+table[i])
        return table[-1]
