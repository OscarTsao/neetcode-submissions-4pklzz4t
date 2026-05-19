class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n = len(heights)
        m = len(heights[0])
        reachPacific = set()
        reachAtlantic = set()
        for i in range(n):
            self.dfs(i, 0, heights, reachPacific)
            self.dfs(i, m-1, heights, reachAtlantic)
        for j in range(m):
            self.dfs(0, j, heights, reachPacific)
            self.dfs(n-1, j, heights, reachAtlantic)

        return [list(coord) for coord in reachPacific.intersection(reachAtlantic)]

    
    def dfs(self, i: int, j: int, heights: List[List[int]], reachable: set):
        n, m = len(heights), len(heights[0])
        direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        reachable.add((i, j))

        for r, c in direction:
            if i+r < 0 or i+r >= n or j+c < 0 or j+c >=m:
                continue

            if (i+r, j+c) not in reachable and heights[i+r][j+c] >= heights[i][j]:
                self.dfs(i+r, j+c, heights, reachable)