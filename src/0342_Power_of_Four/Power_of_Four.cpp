class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num > 0 && (num & (num - 1)) == 0) {
            for(int i = 0; i < 16; i++) {
                if(num == 1) return true;
                num >>= 2; 
            }
        }
        return false;
    }
};
