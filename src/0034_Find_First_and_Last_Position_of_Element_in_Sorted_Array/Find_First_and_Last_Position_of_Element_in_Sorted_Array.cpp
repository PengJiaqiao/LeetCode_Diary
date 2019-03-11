class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        int l = 0, r = nums.size() - 1, m;
        while(l <= r) {
            m = l + (r - l) / 2;
            if(nums[m] == target) {
                l = nums[l] == target ? l : m - 1;
                r = nums[r] == target ? r : m + 1;
                while(l >= 0 && nums[l] == target) l--;
                while(r < nums.size() && nums[r] == target) r++;
                res[0] = l + 1;
                res[1] = r - 1;
                return res;
            }
            else if(nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        return {-1, -1};
    }
};
