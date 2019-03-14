class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(nums.size() == 0) return 0;
        int res = 1;
        vector<int> tails;
        tails.push_back(nums[0]);
        for(int num : nums) {
            int end = tails.size() - 1;
            if(num > tails[end]) tails.push_back(num);
            else {
                int begin = 0, mid;
                while(begin < end) {
                    mid = begin + (end - begin) / 2;
                    if(tails[mid] < num) begin = mid + 1;
                    else end = mid;
                }
                tails[begin] = num;
            }
        }
        return tails.size();
    }
};
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(nums.size() == 0) return 0;
        int res = 1;
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};*/
