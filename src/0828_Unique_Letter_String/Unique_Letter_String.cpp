#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    int uniqueLetterString(string S)
    {
        vector<vector<int>> pos(26, vector<int>(1, -1));
        for (int i = 0; i < S.size(); ++i)
            pos[S[i] - 'A'].push_back(i);
        for (int i = 0; i < 26; ++i)
            pos[i].push_back(S.size());
        int res = 0;
        int mod = pow(10, 9) + 7;
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 1; j < pos[i].size() - 1; ++j)
            {
                res += (pos[i][j] - pos[i][j - 1]) * (pos[i][j + 1] - pos[i][j]);
                res %= mod;
            }
        }
        return res;
    }
};