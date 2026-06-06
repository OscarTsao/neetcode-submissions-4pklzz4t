class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        for (int i = left+1; i <= right; i++) {
            left &= i;
        }
        return left;
    }
};