class Solution {
public:
    int longestMountain(vector<int>& A) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(A.size() < 3) return 0;
        vector<int> diff;
        for(int i = 1; i < A.size(); i++) diff.push_back(A[i] - A[i - 1]);
        int begin = -1, end = -1, length = 0;
        for(int i = 0; i < diff.size(); i++) {
            if(end!= -1 && diff[i] >= 0) {
                length = max(length, end - begin + 2);
                begin = -1;
                end = -1;
            }
            if(end == -1 && diff[i] == 0) begin = -1;
            if(begin == -1 && diff[i] > 0) begin = i;
            if(begin != -1 && diff[i] < 0) end = i;
        }
        if(begin!= -1 && end != -1) length = max(length, end - begin + 2);
        return length;
    }
};
