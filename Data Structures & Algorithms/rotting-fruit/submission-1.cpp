class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }
        
        if (fresh == 0) return 0;
        int ans = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


        while (!q.empty() && fresh) {
            int size = q.size();
            ans++;

            for (int i = 0 ; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (auto& dir: directions) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny]==1) {
                        fresh--;
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
        }
        return (fresh)? -1:ans;
    }
};
