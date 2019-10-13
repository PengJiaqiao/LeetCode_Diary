#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestArithSeqLength(vector<int> &A)
    {
        if (A.size() < 2)
            return A.size();
        int res = 2;
        vector<unordered_map<int, int>> dp(A.size());
        for (int i = 1; i < A.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int diff = A[i] - A[j];
                if (dp[j].find(diff) == dp[j].end())
                    dp[i][diff] = 2;
                else
                {
                    dp[i][diff] = dp[j][diff] + 1;
                    res = max(res, dp[i][diff]);
                }
            }
        }
        return res;
    }
};