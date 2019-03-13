class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp = {};
        vector<vector<int>> res;
        _subsets(nums, tmp, 0, res);
        return res;
    }
private:
    void _subsets(vector<int>& nums, vector<int>& tmp, int begin, vector<vector<int>>& res) {
        res.push_back(tmp);
        for(int i = begin; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            _subsets(nums, tmp, i + 1, res);
            tmp.pop_back();
        }
        return;
    }
};
