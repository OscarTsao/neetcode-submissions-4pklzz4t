class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int land = 0;
        int edge = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ++land;

                    if (i > 0 && grid[i-1][j] == 1) ++edge;
                    if (j > 0 && grid[i][j-1] == 1) ++edge;
                }  
            } 
        }
        return (land*4) - (edge*2);
    }
};