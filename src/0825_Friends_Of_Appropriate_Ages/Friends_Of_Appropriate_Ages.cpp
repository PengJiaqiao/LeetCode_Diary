#include <vector>
using namespace std;

class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        vector<int> counts(121, 0);
        int res = 0;
        for (int a : ages)
        {
            ++counts[a];
        }
        for (int i = 15; i < 121; ++i)
        {
            int lowerbound = i / 2 + 7;
            for (int j = lowerbound + 1; j < i; ++j)
            {
                res += counts[j] * counts[i];
            }
            res += counts[i] * (counts[i] - 1);
        }
        return res;
    }
};