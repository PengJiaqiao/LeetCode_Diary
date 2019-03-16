class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(n == 0) return 0;
        vector<unsigned int> res(n), pre(primes.size(), 0);
        res[0] = 1;
        for(int i = 1; i < n; i++) {
            unsigned int Min = res[pre[0]] * primes[0];
            if(Min > res[i - 1] + 1) {
                for(int j = 1; j < pre.size(); j++) Min = min(Min, res[pre[j]] * primes[j]);
            }
            res[i] = Min;
            for(int j = 0; j < primes.size(); j++) {
                if(res[pre[j]] * primes[j] == Min) pre[j]++;
            }
        }
        return *(res.rbegin());
    }
};
