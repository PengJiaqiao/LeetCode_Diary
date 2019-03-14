class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits[bits.size() - 1] == 1) return false;
        int i = 0;
        while(i < bits.size() - 1) {
            if(bits[i] == 1) i += 2;
            else if(bits[i] == 0) i++;
        }
        return i == bits.size() - 1;
    }
};
