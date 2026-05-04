class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums[0], nums[1])
        else:
            return max(self.rob_action(nums, 0, len(nums)-1), self.rob_action(nums, 1, len(nums)))
    def rob_action(self, nums, l, r):
        dp1, dp2 = 0, 0
        for i in range(l, r):
            new = max(nums[i] + dp1, dp2)
            dp1, dp2 = dp2, new
        return dp2
            
            