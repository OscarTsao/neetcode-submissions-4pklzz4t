class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long value = n - 1;

        int bit = 0;

        while (value > 0) {
            if ((ans & (1LL << bit)) == 0) {
                if (value & 1LL) {
                    ans |= (1LL << bit);
                }
                value >>= 1;
            }
            bit++;
        }
        return ans;
    }
};