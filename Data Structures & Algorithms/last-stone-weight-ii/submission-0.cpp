class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        int n = stones.size();
        for (int x : stones) {
            sum += x;
        }

        int target = sum / 2;
        vector<int> dp(target+1, 0);
        for (int x : stones) {
            for (int i = target; i >= x; i--) {
                dp[i] = max(dp[i], dp[i-x]+x);
            }
        }
        return sum - 2 * dp[target];
    }
};