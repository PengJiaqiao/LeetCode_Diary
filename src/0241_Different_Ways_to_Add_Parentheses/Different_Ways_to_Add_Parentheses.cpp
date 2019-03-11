class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        string operators = {};
        int num = 0, tmp = 0;
        for(char in : input) {
            tmp = in - '0';
            if(tmp >= 0) num = num * 10 + tmp;
            else {
                operators += in;
                nums.push_back(num);
                num = 0;
            }
        }
        nums.push_back(num);
        vector<int> res = helper(nums, operators, 0, nums.size() - 1);
        sort(res.begin(), res.end());
        return res;
    }
private:
    vector<int> helper(vector<int>& nums, string& operators, int begin, int end) {
        if(begin == end) return {nums[begin]};
        vector<int> v1, v2, res;
        for(int i = begin; i < end; i++) {
            v1 = helper(nums, operators, begin, i);
            v2 = helper(nums, operators, i + 1, end);
            if(operators[i] == '*') {
                for(int num1 : v1) {
                    for(int num2 : v2) res.push_back(num1 * num2);
                }
            }
            else if(operators[i] == '+') {
                for(int num1 : v1) {
                    for(int num2 : v2) res.push_back(num1 + num2);
                }
            }
            else {
                for(int num1 : v1) {
                    for(int num2 : v2) res.push_back(num1 - num2);
                }
            }
        }
        return res;
    }
};
