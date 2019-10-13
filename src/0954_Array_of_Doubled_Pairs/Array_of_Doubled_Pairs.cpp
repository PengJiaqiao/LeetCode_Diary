#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    bool canReorderDoubled(vector<int> &A)
    {
        map<int, int> m;
        for (int num : A)
            ++m[num];
        auto it = m.begin();
        while (it != m.end())
        {
            if (it->second == 0)
            {
                ++it;
                continue;
            }
            int target;
            if (it->first < 0)
            {
                if (it->first % 2 == 1)
                    return false;
                target = it->first / 2;
            }
            else
                target = it->first * 2;
            if (m.find(target) == m.end())
                return false;
            if (it->second > m[target])
                return false;
            m[target] -= it->second;
            it = m.erase(it);
        }
        return true;
    }
};