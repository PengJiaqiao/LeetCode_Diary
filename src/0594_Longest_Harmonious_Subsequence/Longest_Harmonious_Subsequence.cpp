class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> M;
        int longest = 0;
        for(int num : nums) M[num] = M.find(num) == M.end()? 1 : (M[num] + 1);
        for(const auto& i : M) {
            auto ptr = M.find(i.first + 1);
            longest = max(longest, ptr == M.end()? 0 : (M[i.first] + ptr->second));
        }
        return longest;
    }
};
