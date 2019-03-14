class Solution { //8 ms
public:
    int findTargetSumWays(vector<int>& nums, int S) { //Find a subset with sum of (target + sum(nums))/2
        int sum = 0;
        for(int num : nums) sum += num;
        if (sum < S || (sum + S) % 2 == 1) {
            return 0;
        }
        int W = (sum + S) / 2;
        vector<int> dp(W + 1); //Dynamic programming
        dp[0] = 1;
        for (int num : nums) {
            for (int i = W; i >= num; i--) dp[i] = dp[i] + dp[i - num];
        }
        return dp[W];
    }
};
/*
class Solution { // 516 ms
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0) return 0;
        return dfs(nums, nums.size() - 1, S);
    }
private:
    int dfs(vector<int>& nums, int idx, long S) {
        if(idx == 0) {
            if(nums[0] == S || nums[0] == -S) return S == 0? 2 : 1;
            else return 0;
        }
        return dfs(nums, idx - 1, S + nums[idx]) + dfs(nums, idx - 1, S - nums[idx]);
    }
};*/
