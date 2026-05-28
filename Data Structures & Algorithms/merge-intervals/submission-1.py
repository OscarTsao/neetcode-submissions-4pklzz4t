class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        intervals.sort()
        res = []

        for i in range(n):
            interval = intervals[i]
            while res and res[-1][1] >= interval[0]:
                interval = [min(res[-1][0], interval[0]), max(res[-1][1], interval[1])]
                res.pop()
            res.append(interval)
        return res                 