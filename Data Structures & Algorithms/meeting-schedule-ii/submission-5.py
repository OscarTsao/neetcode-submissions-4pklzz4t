"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        if not intervals:
            return 0
        count = 0

        started = sorted([i.start for i in intervals])
        ended = sorted([i.end for i in intervals])

        end_ptr = 0

        for start in started:
            if ended[end_ptr] > start:
                count += 1
            else:
                end_ptr += 1
        return count