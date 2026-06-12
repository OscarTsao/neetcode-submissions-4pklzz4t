class Solution {
private:
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& state, int row, int col) {
        int n = heights.size();
        int m = heights[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m || state[row][col]) {
            return;
        }
        state[row][col] = true;
        if (row < n-1 && heights[row][col] <= heights[row+1][col]) {
            dfs(heights, state, row+1, col);
        }
        if (row > 0 && heights[row][col] <= heights[row-1][col]) {
            dfs(heights, state, row-1, col);
        }
        if (col < m-1 && heights[row][col] <= heights[row][col+1]) {
            dfs(heights, state, row, col+1);
        }
        if (col > 0 && heights[row][col] <= heights[row][col-1]) {
            dfs(heights, state, row, col-1);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            dfs(heights, pacific, i, 0);
        }
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, 0, i);
        }
        for (int i = 0; i < n; i++) {
            dfs(heights, atlantic, i, m-1);
        }
        for (int i = 0; i < m; i++) {
            dfs(heights, atlantic, n-1, i);
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (atlantic[i][j] && pacific[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
