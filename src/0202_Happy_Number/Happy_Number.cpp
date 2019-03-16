class Solution {
public:
    unordered_set<int> s;
    bool isHappy(int n) {
        if(n == 1) return true;
        int sum = 0;
        while(n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        if(s.find(sum) != s.end()) return false;
        else s.insert(sum);
        return isHappy(sum);
    }
};
