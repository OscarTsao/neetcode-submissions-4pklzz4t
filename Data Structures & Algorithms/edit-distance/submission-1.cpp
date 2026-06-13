class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> cp(n+1, vector<int>(m+1, 0));
        for (int i = 0; i <= n; i++) {
            cp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            cp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i-1] == word2[j-1]) {
                    cp[i][j] = cp[i-1][j-1];
                }
                else {
                    cp[i][j] = min({cp[i-1][j], cp[i][j-1], cp[i-1][j-1]}) + 1;
                }
            }
        }
        return cp[n][m];
    }
};
