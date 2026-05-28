class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        ans = []
        for n in nums:
            heapq.heappush(ans, n)
            if len(ans) > k:
                heapq.heappop(ans)
        return ans[0]