class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1: 
            return nums[0]
        elif len(nums) == 2:
            return max(nums[0], nums[1])
        else:
            dp1, dp2 = 0, 0
            for n in nums:
                new = max(n+dp1, dp2)
                dp2, dp1 = new, dp2
            return dp2