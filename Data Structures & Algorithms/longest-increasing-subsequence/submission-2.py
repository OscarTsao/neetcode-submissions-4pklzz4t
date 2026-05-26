import bisect
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        sub = []

        for x in nums:
            idx = bisect.bisect_left(sub, x)

            if idx == len(sub):
                sub.append(x)
            else:
                sub[idx] = x
        return len(sub)