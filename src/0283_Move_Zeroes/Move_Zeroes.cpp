class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int idx = -1;
        for(int i = 0; i < nums.size(); i++) 
        {
            if(idx == -1 && nums[i] == 0) idx = i;
            else if(idx != -1 && nums[i]) {
                nums[idx] = nums[i];
                nums[i] = 0;
                idx++;
            }
        }
        return;
    }
};
