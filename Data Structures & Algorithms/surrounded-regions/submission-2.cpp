class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        auto dfs = [&] (auto& self, int i, int j) -> void {
            if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O') return;
            else {
                board[i][j] = 'T';
                self(self, i-1, j);
                self(self, i+1, j);
                self(self, i, j-1);
                self(self, i, j+1);
            }
        };

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(dfs, i, 0);
            if (board[i][m-1] == 'O') dfs(dfs, i, m-1);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(dfs, 0, j);
            if (board[n-1][j] == 'O') dfs(dfs, n-1, j);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};
