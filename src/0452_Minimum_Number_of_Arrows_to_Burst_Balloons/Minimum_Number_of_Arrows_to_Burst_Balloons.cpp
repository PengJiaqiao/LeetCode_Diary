class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(points.size() == 0) return 0;
        sort(points.begin(), points.end(), [&points](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
        int end = points[0].second, count = 1;
        for(pair point : points) {
            if(point.first > end) {
                end = point.second;
                count++;
            }
        }
        return count;
    }
};
