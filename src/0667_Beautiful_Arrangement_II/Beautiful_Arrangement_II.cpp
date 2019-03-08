class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        res.push_back(1);
        for(int i = 1, interval = k; i <= k; i++, interval--) {
            res.push_back(i % 2 == 1 ? res[i - 1] + interval : res[i - 1] - interval);
        }
        for (int i = k + 1; i < n; i++) {
            res.push_back(i + 1);
        }
        return res;
    }
};
