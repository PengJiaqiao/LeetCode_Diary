class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        vector<int> remainder;
        bool isNegative = false;
        if(num < 0) {
            isNegative = true;
            num = -num;
        }
        while(num > 0) {
            remainder.push_back(num % 7);
            num /= 7;
        }
        string res;
        if(isNegative) res.append(1, '-');
        for(int i = remainder.size() - 1; i >= 0; i--) res.append(1, '0' + remainder[i]);
        return res;
    }
};
