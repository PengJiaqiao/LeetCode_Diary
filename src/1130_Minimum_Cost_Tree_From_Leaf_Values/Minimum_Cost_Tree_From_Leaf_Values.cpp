#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int mctFromLeafValues(vector<int> &arr)
    {
        int res = 0;
        while (arr.size() > 1)
        {
            pair<int, int> min_idx = findMinIndex(arr);
            int l, r;
            if (min_idx.second > 0 && min_idx.second < arr.size() - 1)
                l = arr[min_idx.second - 1], r = arr[min_idx.second + 1];
            else if (min_idx.second == arr.size() - 1)
                l = arr[min_idx.second - 1], r = 16;
            else
                l = 16, r = arr[min_idx.second + 1];
            res += min(min_idx.first * l, min_idx.first * r);
            arr.erase(arr.begin() + min_idx.second);
        }
        return res;
    }

private:
    pair<int, int> findMinIndex(vector<int> &arr)
    {
        int min = arr[0];
        int idx = 0;
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                idx = i;
            }
        }
        return make_pair(min, idx);
    }
};