class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums) if(set.find(num) == set.end()) set.insert(num);
        int longest = 0;
        int count;
        int cur;
        for(int num : nums) {
            if(set.find(num) != set.end()) {
                count = 1;
                cur = num + 1;
                set.erase(num);
                while(set.find(cur) != set.end()) {
                    set.erase(cur);
                    count++;
                    cur++;
                }
                cur = num - 1;
                while(set.find(cur) != set.end()) {
                    set.erase(cur);
                    count++;
                    cur--;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
