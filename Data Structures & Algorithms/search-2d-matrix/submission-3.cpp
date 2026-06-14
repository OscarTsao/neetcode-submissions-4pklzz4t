class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int up = 0;
        int down = n-1;

        while (up <= down) {
            int center = up + (down-up) / 2;
            if (matrix[center][0] <= target && target <= matrix[center][m-1]) {
                int l = 0;
                int r = m-1;
                while (l <= r) {
                    int mid = l + (r-l) / 2;
                    if (matrix[center][mid] == target) {
                        return true;
                    }
                    else if (matrix[center][mid] > target) {
                        r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                return false;
            }
            else if (matrix[center][0] > target) {
                down = center - 1;
            }
            else {
                up = center + 1;
            }
        }
        return false;
    }
};
