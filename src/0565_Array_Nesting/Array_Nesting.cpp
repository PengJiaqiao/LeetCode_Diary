class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        int count = 0;
        int idx, tmp;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                idx = i;
                while(idx >= 0) {
                    count++;
                    tmp = nums[idx];
                    nums[idx] = -1;
                    idx = tmp;
                }
                res = max(res, count);
                count = 0;
            }
        }
        return res - 1;
    }
};
