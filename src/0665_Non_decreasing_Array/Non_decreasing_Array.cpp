class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int cnt = 0;
        for (int i = 1; i < nums.size() && cnt < 2; i++) {
            if (nums[i] >= nums[i - 1]) continue;
            cnt++;
            if (i - 2 >= 0 && nums[i - 2] > nums[i]) nums[i] = nums[i - 1];
            else nums[i - 1] = nums[i];
        }
        return cnt <= 1;
    }
};
