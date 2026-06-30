class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> stringStack;
        int currentNum = 0;
        string currentString = "";

        for (char c : s ) {
            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c-'0');
            }
            else if (c == '[') {
                numStack.push(currentNum);
                stringStack.push(currentString);
                currentNum = 0;
                currentString = "";
            }
            else if (c == ']') {
                int n = numStack.top();
                numStack.pop();
                string decodedString = stringStack.top();
                stringStack.pop();
                while (n--) {
                    decodedString += currentString;
                }
                currentString = decodedString;
            }
            else {
                currentString += c;
            }
        }
        return currentString;
    }
};