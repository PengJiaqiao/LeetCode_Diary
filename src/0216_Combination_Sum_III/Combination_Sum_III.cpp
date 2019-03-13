class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        combine(0, n, 1, k, tmp, res);
        return res;
    }
private:
    void combine(int sum, int target, int begin, int k, vector<int>& tmp, vector<vector<int>>& res){
        if(k == 0 && target == sum){
            res.push_back(tmp);
            return;
        }
        if(sum > target)
            return;
        
        for(int i = begin; i <= 9 && i <= target - sum; i++) {
            sum += i;
            tmp.push_back(i);
            combine(sum, target, i + 1, k - 1, tmp, res);
            sum -= i;
            tmp.pop_back();
        }
    }
};
