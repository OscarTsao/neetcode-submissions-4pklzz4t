class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        self.stones = [-s for s in stones]
        heapq.heapify(self.stones)

        while len(self.stones) > 1:
            y, x = -heapq.heappop(self.stones), -heapq.heappop(self.stones)

            if x != y:
                heapq.heappush(self.stones, x-y)
            
        return -self.stones[0] if self.stones else 0
                