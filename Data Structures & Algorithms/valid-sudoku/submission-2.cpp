class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10] = {false};
        bool col[9][10] = {false};
        bool block[9][10] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int value = board[i][j] - '0';
                    int block_idx = (i/3) * 3 + (j/3);

                    if (row[i][value] || col[j][value] || block[block_idx][value]) {
                        return false;
                    }

                    row[i][value] = true;
                    col[j][value] = true;
                    block[block_idx][value] = true;
                }
            }
        }
        return true;
    }
};
