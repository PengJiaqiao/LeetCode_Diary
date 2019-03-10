class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        int count = 0;
        for (int i = 0; i < len && count < n; i++) {
            if (flowerbed[i] == 1) continue;
            int pre = i == 0 ? 0 : flowerbed[i - 1];
            int next = i == len - 1 ? 0 : flowerbed[i + 1];
            if (pre == 0 && next == 0) {
                count++;
                flowerbed[i] = 1;
            }
        }
        return count >= n;
    }
};
