class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int n = bills.size();

        for (int x : bills) {
            if (x == 20 && ten > 0 && five > 0) {
                --ten;
                --five;
            }
            else if (x == 20 && five >= 3) {
                five -= 3;
            }
            else if (x == 10 && five > 0) {
                --five;
                ++ten;
            }
            else if (x == 5){
                ++five;
            }
            else return false;
        }
        return true;
    }
};