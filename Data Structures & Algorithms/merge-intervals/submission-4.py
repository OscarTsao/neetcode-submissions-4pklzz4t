class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        intervals.sort()
        res = [intervals[0]]

        for i in range(1, n):
            interval = intervals[i]
            prev = res[-1]
            if res and prev[1] >= interval[0]:
                interval = [min(prev[0], interval[0]), max(prev[1], interval[1])]
                res.pop()
            res.append(interval)
        return res                 