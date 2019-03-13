class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if(nums.size() <= 1) return {nums};
        vector<int> tmp;
        vector<bool> reached(nums.size(), false);
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        permute(nums, tmp, reached, res);
        return res;
    }
private:
    void permute(vector<int>& nums, vector<int> tmp, vector<bool>& reached, vector<vector<int>>& res) {
        if(tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!reached[i]) {
                if(i > 0 && nums[i] == nums[i - 1] && !reached[i - 1]) continue;
                else {
                    reached[i] = true;
                    tmp.push_back(nums[i]);
                    permute(nums, tmp, reached, res);
                    tmp.pop_back();
                    reached[i] = false;
                }
            }
        }
        return;
    }
};
