#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        vector<int> v(s.size());
        for (int i = 0; i < s.size(); ++i)
            v[i] = abs(s[i] - t[i]);
        int res = 0;
        int l = 0, r = 0;
        int curCost = 0;
        for (; r < s.size(); ++r)
        {
            res = max(res, r - l);
            curCost += v[r];
            while (curCost > maxCost)
                curCost -= v[l++];
        }
        res = max(res, r - l);
        return res;
    }
};