class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        return findUntilAllIncluded(arr, 0);
    }
private:
    int findUntilAllIncluded(vector<int>& arr, int begin) {
        if(begin == arr.size()) return 0;
        if(arr[begin] == begin) return 1 + findUntilAllIncluded(arr, begin + 1);
        int end = arr[begin];
        for(int i = begin + 1; i <= end; i++) {
            if(arr[i] > end) end = arr[i];
        }
        return 1 + findUntilAllIncluded(arr, end + 1);
    }
};
