class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n, m = len(matrix), len(matrix[0])

        up = 0
        down = n - 1
        row = (up + down) // 2

        while (up <= down):
            if matrix[row][0] == target:
                return True
            elif matrix[row][0] > target:
                down = row - 1
            else:
                up = row + 1
            row = (up + down) // 2

        left = 0
        right = m - 1
        col = (left + right) // 2

        while (left <= right):
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                right = col - 1
            else:
                left = col + 1
            col = (left + right) // 2
        return False
        