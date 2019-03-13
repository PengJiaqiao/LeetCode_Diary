class Solution {
public:  
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        combine(0, target, 0, candidates, tmp, res);
        return res;
    }
private:
    void combine(int sum, int target, int k, vector<int>& candidates, vector<int>& tmp, vector<vector<int>>& res){
        if(target == sum){
            res.push_back(tmp);
            return;
        }
        else if(target < sum)
            return;
        
        for(int i = k; i < candidates.size() && candidates[i] <= target - sum; i++) {
            sum += candidates[i];
            tmp.push_back(candidates[i]);
            combine(sum, target, i, candidates, tmp, res);
            sum -= candidates[i];
            tmp.pop_back();
        }
    }
};
