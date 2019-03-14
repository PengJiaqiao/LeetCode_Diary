class NumArray {
public:
    NumArray(vector<int> nums) : nums_sum(nums.size() + 1, 0)
    {
        partial_sum(nums.begin(), nums.end(), nums_sum.begin() + 1);
    }
    
    int sumRange(int i, int j) {
        return nums_sum[j + 1] - nums_sum[i];
    }
private:
    vector<int> nums_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
