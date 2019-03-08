class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        vector<int> res;
        int tmp;
        for(auto& num : nums) {
            if(num > 0) {
                if(nums[num - 1] > 0) nums[num - 1] = -nums[num - 1];
            }
            else {
                tmp = -num;
                if(nums[tmp - 1] > 0) nums[tmp - 1] = -nums[tmp - 1];
            }
        }
        for(int i = 0; i < nums.size(); i++) if(nums[i] > 0) res.push_back(i + 1);
        return res;
    }
};
