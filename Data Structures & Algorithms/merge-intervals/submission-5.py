class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        intervals.sort()
        res = [intervals[0]]

        for start, end in intervals[1:]:
            prev = res[-1]
            if prev[1] >= start:
                prev[1] = max(end, prev[1])
            else:
                res.append([start, end])
        return res                 