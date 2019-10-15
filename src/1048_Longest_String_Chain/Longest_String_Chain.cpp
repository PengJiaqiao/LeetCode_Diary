#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        vector<int> dp(words.size(), 1);
        sort(words.begin(), words.end(), [](string a, string b) { return a.size() < b.size(); });
        int res = 1;
        for (int i = 1; i < words.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (words[i].size() == words[j].size())
                    break;
                if (words[i].size() - words[j].size() != 1)
                    continue;
                if (isPredecessor(words[i], words[j]))
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }

private:
    bool isPredecessor(const string &a, const string &b)
    {
        int i;
        for (i = 0; i < b.size(); ++i)
        {
            if (a[i] != b[i])
                break;
        }
        for (int j = i++; i < a.size(); ++i, ++j)
        {
            if (a[i] != b[j])
                return false;
        }
        return true;
    }
};