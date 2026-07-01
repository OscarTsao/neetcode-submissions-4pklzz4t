class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 0) return 0;
        if (i == n-1 && j == m-1) return 1;
        int path = 0;
        
        grid[i][j] = -1;
        path += dfs(grid, i-1, j, n, m);
        path += dfs(grid, i+1, j, n, m);
        path += dfs(grid, i, j-1, n, m);
        path += dfs(grid, i, j+1, n, m);
        grid[i][j] = 0;

        return path;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;

        return dfs(grid, 0, 0, n, m);

    }
};
