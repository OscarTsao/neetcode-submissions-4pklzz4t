class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.heap = []
        self.k = k

        for n in nums:
            heapq.heappush(self.heap, -n)

    def add(self, val: int) -> int:
        tmp = []
        heapq.heappush(self.heap, -val)

        for _ in range(self.k-1):
            tmp.append(heapq.heappop(self.heap))
            
        res = -self.heap[0]
        
        for n in tmp:
            heapq.heappush(self.heap, n)
        return res
