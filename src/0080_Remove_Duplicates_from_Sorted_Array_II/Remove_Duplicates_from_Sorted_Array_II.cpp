class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = nums.size();
        if (s < 3) return s;
        int count = 0;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] != nums[count]){
                count++;
                nums[count + 1] = nums[i];
            }
        }
        
        return count + 2;
    }
};
