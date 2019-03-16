class Solution {
public:
    int candy(vector<int>& ratings) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int N = ratings.size();
        if(N < 2) return N;
        vector<int> res(N, 1);
        for(int i = 1; i < N; i++) {
            if(ratings[i] > ratings[i - 1]) res[i] = res[i - 1] + 1;
        }
        
        for(int i = N - 1; i > 0; i--) {
            if(ratings[i] < ratings[i - 1]) res[i - 1] = max(res[i - 1], res[i] + 1);
        }
        
        int sum = 0;
        for(int res_ : res) sum += res_;
        return sum;
    }
};
