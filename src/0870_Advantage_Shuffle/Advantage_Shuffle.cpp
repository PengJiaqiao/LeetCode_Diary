#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        vector<int> res;
        map<int, int> cnt;
        for (int num : A)
            ++cnt[num];
        for (int num : B)
        {
            int cur = 0;
            auto it = cnt.upper_bound(num);
            if (it != cnt.end())
                cur = it->first;
            else
                cur = cnt.begin()->first;
            --cnt[cur];
            if (cnt[cur] == 0)
                cnt.erase(cur);
            res.push_back(cur);
        }
        return res;
    }
};