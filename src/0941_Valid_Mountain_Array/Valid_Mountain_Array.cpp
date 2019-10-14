#include <vector>
using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &A)
    {
        if (A.size() < 3)
            return false;
        int i;
        for (i = 1; i < A.size(); ++i)
        {
            if (A[i] == A[i - 1])
                return false;
            if (A[i] < A[i - 1])
                break;
        }
        if (i == 1 || i == A.size())
            return false;
        for (i = i + 1; i < A.size(); ++i)
        {
            if (A[i] >= A[i - 1])
                return false;
        }
        return true;
    }
};