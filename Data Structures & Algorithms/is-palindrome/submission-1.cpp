class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i <= j){
            while (!isAlphaNum(s[i]) && i < s.size()) i++;
            while (!isAlphaNum(s[j]) && j >= 0) j--;
            if (tolower(s[i]) != tolower(s[j])) return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
private:
    bool isAlphaNum(char& c){
        if ((c >= 'A' && c <= 'Z') || ( c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
            return true;
        }
        else return false;
    }
};
