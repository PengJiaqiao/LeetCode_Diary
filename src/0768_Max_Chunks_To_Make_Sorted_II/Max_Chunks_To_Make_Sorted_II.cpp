class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        int res = 1;
        helper(arr, 1, arr[0], res);
        return res;
    }
private:
    //return the minimum number after arr[idx]
    int helper(vector<int>& arr, int idx, int cur, int& res) {//cur is the maximum number before arr[idx]
        if(idx == arr.size() - 1) {
            if(arr[idx] >= cur) res++;
            return arr[idx];
        }
        if(arr[idx] < cur) {
            int Min = helper(arr, idx + 1, cur, res);
            if(Min > arr[idx]) return arr[idx];
            else return Min; 
        }
        else {
            int Min = helper(arr, idx + 1, arr[idx], res);
            if(Min >= cur) {
                res++;
                return min(Min, arr[idx]);
            }
            else return Min;
        }
    }
};
