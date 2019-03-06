class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> v(nums.size(), -1);
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < nums.size(); i++) {
                while (!s.empty() && nums[s.top()] < nums[i])
                {
                    v[s.top()] = nums[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        return v;
    }
};
