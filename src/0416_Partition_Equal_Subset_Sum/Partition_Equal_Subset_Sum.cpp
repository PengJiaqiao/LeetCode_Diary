class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 0) return true;
        int sum = 0;
        for(int& num : nums) sum += num;
        if(sum % 2 != 0) return false;
        sum /= 2;
        vector<int> res(sum + 1, false);
        res[0] = true;
        for(int& num : nums) {
            for(int i = sum; i >= num; i--) res[i] = res[i] || res[i - num];
        }
        return res[sum];
    }
};
