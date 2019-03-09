class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> M;
        for(int i = 0;i < nums.size(); i++){
            if(M[nums[i]] == 0) M[nums[i]] = i+1;
            else{
                if(i - (M[nums[i]] - 1) <= k) return true;
                else M[nums[i]] = i + 1;
            }
        }
        return false;
    }
};
