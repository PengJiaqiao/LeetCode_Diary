class Solution {
public:
    string frequencySort(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        unordered_map<int, int> M;
        vector<int> v;
        int idx;
        string res = {};
        for(char letter : s) {
            idx = letter - 'A';
            if(idx < 26) M[idx]++; 
            else M[idx - 6]++;
        }
        for(auto m : M) v.push_back(m.first);
        sort(v.begin(), v.end(), [&M](int a, int b) { return M[a] > M[b]; });
        for(int idx : v) {
            if(idx < 26) {
                for(int i = 0; i < M[idx]; i++) res += 'A' + idx;
            }
            else {
                for(int i = 0; i < M[idx]; i++) res += 'A' + idx + 6;
            }
        }
        return res;
    }
};
