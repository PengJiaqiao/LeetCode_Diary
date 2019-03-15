class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;
        vector<int> left(n), right(n); // width of rectangle with height 'heights[i]'
        left[0] = 0, right[n - 1] = 0;
        for(int i = 1; i < n; i++) {
            int tmp = i - 1;
            while(1) {
                if(tmp >= 0 && heights[i] <= heights[tmp]) tmp -= left[tmp] + 1;
                else {
                    left[i] = i - tmp - 1;
                    break;
                }
            }
        }
        for(int i = n - 2; i >= 0; i--) {
            int tmp = i + 1;
            while(1) {
                if(tmp < n && heights[i] <= heights[tmp]) tmp += right[tmp] + 1;
                else {
                    right[i] = tmp - i - 1;
                    break;
                }
            }
        }
        int Max = 0;
        for(int i = 0; i < n; i++) Max = max(Max, heights[i] * (left[i] + right[i] + 1));
        return Max;
    }
};
