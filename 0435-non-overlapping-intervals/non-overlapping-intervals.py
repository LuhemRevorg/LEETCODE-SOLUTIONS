class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        intervals.sort(key=lambda x: x[1])

        count = 0
        end = intervals[0][1]
        for i in intervals[1:]:
            if end == i[1] or i[0] < end:
                count += 1
            else:
                end = i[1]
        return count
