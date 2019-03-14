class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3) return 0;
        int count = 0, tmp = 0;//tmp: how much subsets the privious arithmetic slice contain
        for(int i = 2; i < A.size(); i++) {
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                tmp++;
                count += tmp;
            }
            else tmp = 0;
        }
        return count;
    }
};
