class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs[0].length();
        int m = strs.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (strs[j][i] != strs[0][i]) return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};