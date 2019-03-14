class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> diff(nums.size() - 1);
        for(int i = 0; i < diff.size(); i++) diff[i] = nums[i + 1] - nums[i];
        int count = 1, pre;
        for(int i = 0; i < diff.size(); i++) {
            if(count == 1 && diff[i] != 0) {
                count++;
                pre = diff[i];
            }
            if(diff[i] * pre < 0) {
                count++;
                pre = diff[i];
            }
        }
        return count;
    }
};
