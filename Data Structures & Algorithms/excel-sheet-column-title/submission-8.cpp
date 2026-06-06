class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while (columnNumber > 0) {
            columnNumber--;
            char number = 'A' + (columnNumber % 26);
            columnNumber /= 26;
            ans = number + ans;
            
        }
        return ans;
    }
};