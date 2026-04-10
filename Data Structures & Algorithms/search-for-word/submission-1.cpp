class Solution {
public:
    bool exist(vector<vector<char>>& board, const string& word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == word[0] && dfs(board, word, 0, i, j, m, n)) return true;
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int index, int i, int j, int m, int n){
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[index]) return false;

        if (index == word.size() - 1) return true;

        board[i][j] = '#';

        if (dfs(board, word, index + 1, i - 1, j, m, n)
            || dfs(board, word, index + 1, i + 1, j, m, n)
            || dfs(board, word, index + 1, i, j + 1, m, n)
            || dfs(board, word, index + 1, i, j - 1, m, n)){
                return true;
            }

        board[i][j] = word[index];

        return false;
    }

};
