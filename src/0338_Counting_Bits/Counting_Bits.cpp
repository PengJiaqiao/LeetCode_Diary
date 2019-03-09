class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0) return {0};
        vector<int> v(num + 1);
        int begin = 1, end = 2;
        while(end <= num) {
            v[begin] = 1;
            for(int i = begin + 1, j = 1; i < end; i++, j++) v[i] = 1 + v[j];
            begin *= 2;
            end *= 2;
        }
        v[begin] = 1;
        for(int i = begin + 1, j = 1; i <= num; i++, j++) v[i] = 1 + v[j];
        return v;
    }
};
