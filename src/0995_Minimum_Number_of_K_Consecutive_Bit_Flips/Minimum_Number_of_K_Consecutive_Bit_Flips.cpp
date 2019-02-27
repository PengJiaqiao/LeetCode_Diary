class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        if (A.size() < K) return -1;
        int count = 0;
        for(int i = 0; i <= A.size() - K; i++){
            if(A[i] == 0){
                for(int j = i; j < i + K; j++){
                    A[j] = 1 - A[j];
                }
                count++;
            }
        }
        for(int i = A.size() - K + 1; i < A.size(); i++){
            if(A[i] == 0)return -1;
        }
        return count;
    }
};
