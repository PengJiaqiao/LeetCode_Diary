#include <vector>
using namespace std;

class Solution
{
public:
    int findIntegers(int num)
    {
        vector<int> f(31, 0);
        f[0] = 1, f[1] = 2;
        for (int i = 2; i < 31; ++i)
            f[i] = f[i - 1] + f[i - 2];
        int res = 0, k = 30, pre = 0;
        while (k >= 0)
        {
            if (num & (1 << k))
            {
                res += f[k];
                if (pre)
                    return res;
                pre = 1;
            }
            else
                pre = 0;
            --k;
        }
        return res + 1;
    }
};

// Time Limit Exceeded
/*class Solution
{
public:
    int findIntegers(int num)
    {
        if (num == 1)
            return 2;
        int n = 0, tmp = num;
        while (tmp)
        {
            ++n;
            tmp >>= 1;
        }
        int res = 1;
        queue<int> q;
        q.push(1);
        while (--n)
        {
            int size = q.size();
            res += size;
            for (int i = 0; i < size; ++i)
            {
                int tmp = q.front();
                if (tmp % 2 == 0)
                {
                    tmp <<= 1;
                    q.push(tmp);
                    q.push(tmp + 1);
                }
                else
                {
                    tmp <<= 1;
                    q.push(tmp);
                }
                q.pop();
            }
        }
        while (!q.empty())
        {
            if (q.front() > num)
                break;
            ++res;
            q.pop();
        }
        return res;
    }
};*/