class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x:  x[1])

        count = 1
        end = points[0][1]

        for i in points[1:]:

            if i[0] > end:
                count += 1
                end = i[1]
        return count
