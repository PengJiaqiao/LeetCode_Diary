class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> heap;
        for (auto line : matrix) {
            for (auto elem : line) {
                heap.push(elem);
                if (heap.size() > k) {
                    heap.pop();
                }
            }
        }
        return heap.top();
    }
};
