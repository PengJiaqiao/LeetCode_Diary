class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int idx_1 = 0, idx_2 = A.size() - 1, tmp;
        while(1) {
            while(idx_1 < A.size() && A[idx_1] % 2 == 0) idx_1++;
            while(idx_2 >= 0 && A[idx_2] % 2 == 1) idx_2--;
            if(idx_1 > idx_2 || idx_1 == A.size() || idx_2 < 0) break;
            tmp = A[idx_1];
            A[idx_1] = A[idx_2];
            A[idx_2] = tmp;
        }
        return A;
    }
};
