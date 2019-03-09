class Solution {
public:
    bool hasAlternatingBits(int n) {
        long int a = (n ^ (n >> 1));
        return (a & (a + 1)) == 0;
    }
};
