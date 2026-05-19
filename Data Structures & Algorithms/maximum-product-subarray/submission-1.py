class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        smallest, largest, res = nums[0], nums[0], nums[0]

        for i in range(1, n):
            smallest *= nums[i]
            largest *= nums[i]
            tmp = smallest
            smallest = min(smallest, largest, nums[i])
            largest = max(tmp, largest, nums[i])
            res = max(res, largest)
        return res

