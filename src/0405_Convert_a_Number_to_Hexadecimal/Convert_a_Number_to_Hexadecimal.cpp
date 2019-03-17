class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        vector<int> res;
        int tmp = 15; // binary 1111
        while(num != 0) {
            res.push_back(num & tmp);
            num = (unsigned)num >> 4;
        }
        string s;
        for(int i = res.size() - 1; i >= 0; i--) {
            if(res[i] < 10) s.append(1, '0' + res[i]);
            else s.append(1, 'a' + res[i] - 10);
        }
        return s;
    }
};
