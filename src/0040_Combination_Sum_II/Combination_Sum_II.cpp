class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        combine(0, target, 0, candidates, tmp, res);
        return res;
    }
private:
    void combine(int sum, int target, int k, vector<int>& candidates, vector<int>& tmp, vector<vector<int>>& res) {
        if(target == sum){
            res.push_back(tmp);
            return;
        }
        else if(target < sum) return;
        
        for(int i = k; i < candidates.size() && candidates[i] <= target - sum; i++) {
            if(i > k && candidates[i] == candidates[i - 1]) continue;
            sum += candidates[i];
            tmp.push_back(candidates[i]);
            combine(sum, target, i + 1, candidates, tmp, res);
            sum -= candidates[i];
            tmp.pop_back();
        }
        return;
    }
};
