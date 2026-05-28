class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        distance, ans = [], []

        for x, y in points:
            heapq.heappush(distance, (-(x**2+y**2), x, y))
            if len(distance) > k:
                heapq.heappop(distance)
        return [[x, y] for _, x, y in distance]



            