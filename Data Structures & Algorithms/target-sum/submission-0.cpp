class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        if ((sum+target) % 2 != 0 || abs(target) > sum) return 0;

        int w = (sum+target) / 2;
        vector<int> dp(w+1, 0);
        dp[0] = 1;

        for (int x : nums) {
            for (int j = w; j >= x; j--) {
                dp[j] = dp[j] + dp[j-x];
            }
        }
        return dp[w];
    }
};
