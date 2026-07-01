class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        int count = -1;
        queue<pair<int, int>> q;
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()) {
            count++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                if (x == n-1 && y == m-1) return count;
                for (int j = 0; j < 4; j++) {
                    int nr = x + dr[j];
                    int nc = y + dc[j];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0) {
                        q.push({nr, nc});
                        grid[nr][nc] = 1;
                    }
                }
            }
        }

        return -1;
        
    }
};
