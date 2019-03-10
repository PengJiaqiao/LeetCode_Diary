class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0, i = 0;
        for(int child : g) {
            while(i < s.size()) {
                if(s[i] >= child) {
                    count++;
                    i++;
                    break;
                }
                i++;
            }
        }
        return count;
    }
};
