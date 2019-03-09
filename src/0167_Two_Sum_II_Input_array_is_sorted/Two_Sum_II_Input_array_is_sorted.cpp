class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2);
        int i = 0, j = numbers.size() - 1, sum;
        while(i < j) {
            sum = numbers[i] + numbers[j];
            if(sum == target) break;
            else if(sum < target) i++;
            else j--;
        }
        res[0] = i + 1;
        res[1] = j + 1;
        return res;
    }
};
