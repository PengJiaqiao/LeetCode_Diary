class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int cur = 0;
        int Max = 0;
        for(auto& num : nums) 
        {
            if(num == 1) cur++;
            else {
                Max = max(cur, Max);
                cur = 0;
            }
        }
        return max(cur, Max);
    }
};
