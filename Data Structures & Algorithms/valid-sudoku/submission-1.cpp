class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9, unordered_set<int>());
        vector<unordered_set<int>> col(9, unordered_set<int>());
        vector<vector<unordered_set<int>>> block(3, vector<unordered_set<int>>(3, unordered_set<int>()));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int value = board[i][j] - '0';
                    if (row[i].count(value)) {
                        return false;
                    }
                    if (col[j].count(value)) {
                        return false;
                    }
                    if (block[i/3][j/3].count(value)) {
                        return false;
                    }
                    row[i].insert(value);
                    col[j].insert(value);
                    block[i/3][j/3].insert(value);
                }
            }
        }
        return true;
    }
};
