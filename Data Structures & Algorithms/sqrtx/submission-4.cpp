class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;

        while (l <= r) {
            int mid = l + (r-l) / 2;
            long long int num = 1LL * mid * mid;
            if (num == x) return mid;
            else if (num < x) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};