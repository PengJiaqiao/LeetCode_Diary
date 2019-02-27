class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> M;
        for (int i = 0; i < nums.size(); i++)
        {
            int numberToFind = target - nums[i];
            if (M.find(numberToFind) != M.end()) {
                result.push_back(M[numberToFind]);
                result.push_back(i);			
                return result;
            }

            M[nums[i]] = i;
        }
    }
};
