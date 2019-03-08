class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> fre, l, r;
        for(int i = 0; i < nums.size(); i++) {
            if(fre.find(nums[i]) == fre.end()) fre[nums[i]] = 1;
            else fre[nums[i]]++;
            if(l.find(nums[i]) == l.end()) l[nums[i]] = i;
            r[nums[i]] = i;
        }
        int fre_, Max = fre[nums[0]];
        vector<int> v;
        for(auto num : nums) {
            fre_ = fre[num];
            if(fre_ > Max) {
                Max = fre_;
                v.clear();
                v.push_back(num);
            }
            else if(fre_ == Max) v.push_back(num);
        }
        int Min = nums.size();
        for(auto num : v) Min = min(Min, r[num] - l[num]);
        return Min + 1;
    }
};
