class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cur = 0, begin = 0, end = nums.size() - 1;
        while(cur <= end) {
            if (nums[cur] == 0) {
                swap(nums, cur, begin);
                begin++;
                cur++;
            }
            else if (nums[cur] == 1) cur++;
            else {
                swap(nums, cur, end);
                end--;
            }
        }
        return;
    }
private:
    void swap(vector<int>& nums, int idx1, int idx2) {
        int tmp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = tmp;
        return;
    }
};
