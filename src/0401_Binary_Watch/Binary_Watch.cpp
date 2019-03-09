class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        if(num == 0) return {"0:00"};
        vector<string> res, res_h, res_m;
        for(int i = 0; i <= min(num, 4); i++) {
            res_h = H_helper(i);
            res_m = M_helper(num - i);
            for(int j = 0; j < res_h.size(); j++) {
                for(int k = 0; k < res_m.size(); k++) res.push_back(res_h[j] + ":" + res_m[k]);
            }
        }
        return res;
    }
private:
    vector<string> H_helper(int num) { //hour
        vector<string> res;
        switch(num) {
            case 0 : res = {"0"};
                break;
            case 1 : res = {"1", "2", "4", "8"};
                break;
            case 2 : res = {"3", "5", "6", "9", "10"};
                break;
            case 3 : res = {"7", "11"};
                break;
            case 4 : res = {};
                break;
        }
        return res;
    }
    vector<string> M_helper(int num) { //minute
        vector<string> res;
        switch(num) {
            case 0 : res = {"00"};
                break;
            case 1 : res = {"01", "02", "04", "08", "16", "32"};
                break;
            case 2 : res = {"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"};
                break;
            case 3 : res = {"07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49", "50", "52", "56"};
                break;
            case 4 : res = {"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58"};
                break;
            case 5 : res = {"31", "47", "55", "59"};
                break;
            case 6 : res = {};
                break;
        }
        return res;
    }
};
