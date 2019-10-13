#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> v(n, vector<int>(n, 0));
        helper(v, 0, n - 1, 1);
        return v;
    }

private:
    void helper(vector<vector<int>> &v, int round, int length, int start)
    {
        if (length <= 0)
        {
            v[round][round] = v[round][round] == 0 ? start : v[round][round];
            return;
        }
        int num = start;
        for (int i = 0; i < length; ++i)
            v[round][round + i] = num++;
        for (int i = 0; i < length; ++i)
            v[round + i][round + length] = num++;
        for (int i = length; i > 0; --i)
            v[round + length][round + i] = num++;
        for (int i = length; i > 0; --i)
            v[round + i][round] = num++;
        helper(v, ++round, length - 2, num);
        return;
    }
};