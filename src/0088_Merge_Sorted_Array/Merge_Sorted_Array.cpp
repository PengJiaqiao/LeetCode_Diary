class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k;
        for(k = m + n - 1; k >= 0 && i >= 0 && j >= 0; k--) {
            if(nums1[i] < nums2[j]) {
                nums1[k] = nums2[j];
                j--;
            }
            else {
                nums1[k] = nums1[i];
                i--;
            }
        }
        if(i < 0) copy(nums2.begin(), nums2.begin() + k + 1, nums1.begin());
        return;
    }
};
