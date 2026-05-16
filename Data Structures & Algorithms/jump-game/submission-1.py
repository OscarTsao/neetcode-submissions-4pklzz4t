class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        reach = [True] + [False] * (n)
        for i in range(n):
            if reach[i] == True:
                if i+nums[i] >= n-1:
                    return True
                else:
                    for j in range(nums[i]+1):
                        reach[i+j] = True
            
        
        return False