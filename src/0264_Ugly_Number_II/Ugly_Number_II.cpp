class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n);
        res[0] = 1;
        int pre_2 = 0, pre_3 = 0, pre_5 = 0;
        for(int i = 1; i < n; i++) {
            int Min = min(res[pre_2] * 2, min(res[pre_3] * 3, res[pre_5] * 5));
            res[i] = Min;
            if(Min == res[pre_2] * 2) pre_2++;
            if(Min == res[pre_3] * 3) pre_3++;
            if(Min == res[pre_5] * 5) pre_5++;
        }
        return *(res.rbegin());
    }
};
