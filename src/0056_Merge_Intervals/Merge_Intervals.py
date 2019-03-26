# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals: List[Interval]) -> List[Interval]:
        if not intervals: return []
        intervals.sort(key = lambda interval: interval.start)
        res, start, end = [], intervals[0].start, intervals[0].end
        for interval in intervals:
            if end < interval.start: 
                res.append([start, end])
                start, end = interval.start, interval.end
            else: end = max(end, interval.end)
        res.append([start, end])
        return res
