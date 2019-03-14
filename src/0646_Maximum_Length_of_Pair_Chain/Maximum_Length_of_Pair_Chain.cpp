class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){ return a[1] < b[1]; });
        int tail = pairs[0][1], count = 1;
        for(auto& pair : pairs) {
            if(pair[0] > tail) {
                count++;
                tail = pair[1];
            }
        }
        return count;
    }
};
