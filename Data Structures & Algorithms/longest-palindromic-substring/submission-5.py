class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False] * n for _ in range(n)]

        res = ""

        for length in range(1, n+1):
            for l in range(n-length+1):
                r = l + length - 1

                if s[l] == s[r] and (length <= 3 or dp[l+1][r-1]):
                    dp[l][r] = True

                    if length > len(res):
                        res = s[l:r+1]
        return res