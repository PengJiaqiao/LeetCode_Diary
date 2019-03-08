class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int begin, end;
        begin = 1;
        end = nums.size() - 1;
        while(begin != end) {
            int mid = (begin + end) / 2;
            int count = 0;
            for(int i = 0; i < nums.size(); i++) if(nums[i] <= mid) count++;
            if(count <= mid) begin = mid + 1;
            else end = mid;
        }
        return begin;
    }
};
