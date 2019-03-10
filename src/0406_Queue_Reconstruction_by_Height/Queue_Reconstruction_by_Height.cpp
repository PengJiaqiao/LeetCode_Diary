class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        sort(people.begin(), people.end(), [&people](pair<int, int> a, pair<int, int> b) { return a.first > b.first || a.first == b.first && a.second < b.second; });
        vector<pair<int, int>> res;
        for(auto p : people) res.insert(res.begin() + p.second, p);
        return res;
    }
};
