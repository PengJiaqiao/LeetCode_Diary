/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [&intervals](Interval a, Interval b) { return a.end < b.end; });
        int end = intervals[0].end, count = 1;
        for(Interval i : intervals) {
            if(i.start >= end) {
                end = i.end;
                count++;
            }
        }
        return intervals.size() - count;
    }
};
