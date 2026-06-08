class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> cols;
        unordered_set<int> diag;
        unordered_set<int> antiDiag;

        auto backtrack = [&] (auto& self, int row) -> void {
            if (row == n) {
                ans.push_back(board);
                return;
            }

            for (int c = 0; c < n; ++c) {
                int d = row-c;
                int ad = row+c;
                if (cols.count(c) || diag.count(d) || antiDiag.count(ad)) {
                    continue;
                }
                else {
                    board[row][c] = 'Q';
                    cols.insert(c);
                    diag.insert(d);
                    antiDiag.insert(ad);
                    self(self, row+1);
                    board[row][c] = '.';
                    cols.erase(c);
                    diag.erase(d);
                    antiDiag.erase(ad);
                }
            }
        };

        backtrack(backtrack, 0);
        
        return ans;
    }
};
