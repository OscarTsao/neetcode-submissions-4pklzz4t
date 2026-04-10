class Solution {
public:
    int getSum(int a, int b) {
        int sum = a ^ b;
        int carry = a & b;
        carry <<= 1;
        return carry + sum;

    }
};
