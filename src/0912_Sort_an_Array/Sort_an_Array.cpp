#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void QuickSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return;
        int threshold = nums[low];
        int i = low + 1;
        int j = high;
        while (i < j)
        {
            while (i < j && nums[i] <= threshold)
                ++i;
            while (i < j && nums[j] >= threshold)
                --j;
            swap(nums[i], nums[j]);
        }
        if (nums[i] < threshold)
            swap(nums[low], nums[i]);
        QuickSort(nums, low, i - 1);
        QuickSort(nums, i, high);
        return;
    }
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
        return;
    }
};