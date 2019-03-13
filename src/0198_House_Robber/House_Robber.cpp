class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        int s1 = nums[0], s2 = max(nums[0], nums[1]), s3;
        for(int i = 2; i < nums.size(); i++) {
            s3 = max(s1 + nums[i], s2);
            s1 = s2;
            s2 = s3;
        }
        return s3;
    }
};
