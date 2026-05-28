class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n, m = len(matrix), len(matrix[0])

        left = 0
        right = n * m - 1

        while (left <= right):
            pivot = (left + right) // 2
            row, col = pivot // m, pivot % m

            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                right = pivot - 1
            else:
                left = pivot + 1
        return False