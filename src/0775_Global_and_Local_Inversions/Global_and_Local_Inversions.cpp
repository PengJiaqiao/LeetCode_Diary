class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if (A.size() <= 2) return true;
        for (int i = 0, maxn = -1; i < A.size() - 2; i++) {
            maxn = max(maxn, A[i]);
            if (maxn > A[i+2]) return false;
        }
        return true;
    }
};
