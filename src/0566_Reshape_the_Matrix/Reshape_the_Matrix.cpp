class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int r_ = nums.size();
        if(r_ == 0) return {};
        
        int c_ = nums[0].size();
        if(r_ * c_  != r * c) return nums;
        
        vector<int> tmp;
        vector<vector<int>> res;
        int idx = 0;
        for(int i = 0; i < r; i++) 
        {
            for(int j = 0; j < c; j++)
            {
                tmp.push_back(nums[idx / c_][idx % c_]);
                idx++;
            }
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};
