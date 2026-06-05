class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;

        auto dfs = [&] (auto& self, int i, int j) -> int {
            if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != 0) {
                grid[i][j] = 0;
                return 1 + self(self, i-1, j) + self(self, i+1, j) + self(self, i, j-1) + self(self, i, j+1);
            }
            else return 0;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int area = 0;
                if (grid[i][j] != 0) {
                    maxArea = max(maxArea, dfs(dfs, i, j));
                }
            }
        }
        return maxArea;
    }
};
