class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tmp;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) 
        {
            while(nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) 
            {
                tmp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = tmp;
            }
        }
        for(int i = 0; i < nums.size(); i++) 
        {
            if(nums[i] != i + 1) 
            {
                res.push_back(nums[i]);
                res.push_back(i + 1);
                break;
            }
        }
        return res;
    }
};
