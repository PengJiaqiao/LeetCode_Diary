class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return {0};
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        int size = 2;
        for(int i = 1; i < n; i++) {
            for(int j = size - 1; j >= 0; j--) res.push_back(res[j] + (1 << i));
            size *= 2;
        }
        return res;
    }
};
