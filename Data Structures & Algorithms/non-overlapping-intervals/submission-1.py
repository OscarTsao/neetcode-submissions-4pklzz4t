class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        removed = 0
        intervals.sort(key = lambda x : x[1])
        prev = intervals[0][1]

        for start, end in intervals[1:]:
            if prev > start:
                removed += 1
                prev = min(end, prev)
            else:
                prev = end
        return removed