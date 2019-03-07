class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] > 0) nums[i] += nums[i - 1];
            res = max(res, nums[i]);
        }
        return res;
    }
};
