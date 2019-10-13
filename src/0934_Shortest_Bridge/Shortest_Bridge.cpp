#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int shortestBridge(vector<vector<int>> &A)
    {
        vector<pair<int, int>> island1;
        vector<pair<int, int>> island2;
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = 0; j < A[0].size(); ++j)
            {
                if (A[i][j] == 1)
                {
                    search(A, i, j, island1);
                    i = A.size();
                    break;
                }
            }
        }
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = 0; j < A[0].size(); ++j)
            {
                if (A[i][j] == 1)
                {
                    search(A, i, j, island2);
                    i = A.size();
                    break;
                }
            }
        }
        int res = 200;
        for (pair<int, int> i : island1)
        {
            for (pair<int, int> j : island2)
            {
                res = min(res, abs(i.first - j.first) + abs(i.second - j.second) - 1);
            }
        }
        return res;
    }

private:
    void search(vector<vector<int>> &A, int i, int j, vector<pair<int, int>> &island)
    {
        if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size())
            return;
        if (A[i][j] == 0)
            return;
        island.push_back(make_pair(i, j));
        A[i][j] = 0;
        search(A, i - 1, j, island);
        search(A, i + 1, j, island);
        search(A, i, j + 1, island);
        search(A, i, j - 1, island);
        return;
    }
};