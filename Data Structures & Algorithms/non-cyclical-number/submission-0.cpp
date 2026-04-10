class Solution {
private:
    int sumOfSquare(int n){
        int result = 0;
        while (n != 0){
            result += (n % 10) * (n % 10);
            n /= 10;
        }
        return result;
    }

public:
    bool isHappy(int n) {
        int slow = n, fast = sumOfSquare(n);
        while (slow != fast){
            slow = sumOfSquare(slow);
            fast = sumOfSquare(fast);
            fast = sumOfSquare(fast);
        }    
        return fast == 1;
    }
};
