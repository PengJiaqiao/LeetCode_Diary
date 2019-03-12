class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(n < k) return {};
        if(n == k) {
            vector<int> res;
            for(int i = 1; i <= n; i++) res.push_back(i);
            return {res};
        }
        if(k == 1) {
            vector<vector<int>> res;
            for(int i = 1; i <= n; i++) res.push_back({i});
            return res;
        }
        
        vector<vector<int>> res, with_n, without_n;
        with_n = combine(n - 1, k - 1);
        for(auto& com : with_n) {
            com.push_back(n);
            res.push_back(com);
        }
        without_n = combine(n - 1, k);
        for(auto& com : without_n) res.push_back(com);
        return res;
    }
};
