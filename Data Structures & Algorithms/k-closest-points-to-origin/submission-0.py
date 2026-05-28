class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        ans = []
        distance = [(points[i][0]**2 + points[i][1]**2, i) for i in range(len(points))]

        heapq.heapify(distance)

        for i in range(k):
            ans.append(points[heapq.heappop(distance)[1]])
        return ans
            