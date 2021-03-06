class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int l = 1, h = x / 2;
        int mid, sqrt;
        while (l <= h) { 
            mid = l + (h - l) / 2;
            sqrt = x / mid;
            if (sqrt == mid) return mid;
            else if (mid > sqrt) h = mid - 1;
            else l = mid + 1;
        }
        return h;
    }
};
