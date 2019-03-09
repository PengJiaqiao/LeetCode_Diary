class Solution {
public:
    bool judgeSquareSum(int c) {
        long begin = 0, end = (int)sqrt(c);
        long sum;
        while(begin <= end) {
            sum = begin * begin + end * end;
            if(sum == c) return true;
            else if(sum < c) begin++;
            else end--;
        }
        return false;
    }
};
