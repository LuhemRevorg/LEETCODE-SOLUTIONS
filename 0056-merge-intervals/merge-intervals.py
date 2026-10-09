class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        # Sort by start index
        # [1,3] [2,6] first.end >= second.start => merge
        # New interval is [first.start, second.end]

        ret = []
        intervals.sort()

        for i in range(len(intervals) - 1):
            first = intervals[i]
            second = intervals[i+1]

            if first[1] >= second[0]:
                second[0] = first[0]
                second[1] = max(first[1], second[1])
            else:
                ret.append(first)

        ret.append(intervals[-1])    
        
        return ret
