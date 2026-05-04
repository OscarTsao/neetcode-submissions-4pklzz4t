class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums[0], nums[1])
        else:
            dp1, dp2 = 0, 0
            for i in range(0, len(nums) - 1):
                new_first = max(nums[i]+dp1, dp2)
                dp1, dp2 = dp2, new_first
            dp1, dp2 = 0, 0
            for i in range(1, len(nums)):
                new_last = max(nums[i] + dp1, dp2)
                dp1, dp2 = dp2, new_last
            return max(new_first, new_last)
            
            