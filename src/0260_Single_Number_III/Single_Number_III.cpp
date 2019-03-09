class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int num : nums) diff ^= num;
        diff &= -diff;  //the first 1 from right
        vector<int> res(2, 0);
        for (int num : nums) {
            if ((num & diff) == 0) res[1] ^= num;
            else res[0] ^= num;
        }
        return res;
    }
};
