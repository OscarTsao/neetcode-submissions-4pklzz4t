class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0;
        int n = word1.length(), m = word2.length();

        while (i < n && i < m) {
            ans += word1[i];
            ans += word2[i];
            i++;
        }
        if (n > m) ans += word1.substr(i, n-i+1);
        if (n < m) ans += word2.substr(i, m-i+1);
        return ans;
    }
};