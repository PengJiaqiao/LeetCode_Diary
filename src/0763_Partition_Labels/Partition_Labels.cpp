class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<pair<int, int>> v(26, {-1, -1});
        for(int i = 0; i < S.size(); i++) {
            int idx = S[i] - 'a';
            if(v[idx].first == -1) v[idx].first = i;
            v[idx].second = i;
        }
        sort(v.begin(), v.end(), [&v](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
        int left = v[0].first, right = v[0].second;
        vector<int> res;
        for(auto letter : v) {
            if(letter.first > right) {
                if(right != -1) res.push_back(right - left + 1);
                left = letter.first;
                right = letter.second;
            }
            else right = max(right, letter.second);
        }
        res.push_back(right - left + 1);
        return res;
    }
};
