# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        intervals.sort(key=lambda interval: interval.start)
        res = []
        for interval in intervals:
            flag = True
            for i, v in enumerate(res):
                if interval.start >= v: 
                    res[i] = interval.end
                    flag = False
                    break
            if flag: res.append(interval.end)
        return len(res)
