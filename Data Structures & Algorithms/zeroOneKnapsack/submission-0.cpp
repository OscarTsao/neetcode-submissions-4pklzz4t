class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int n = profit.size();
        vector<int> dp(capacity+1, 0);

        for (int i = 0; i < n; i++) {
            int value = profit[i];
            int load = weight[i];

            for (int j = capacity; j >= load; j--) {
                dp[j] = max(dp[j], dp[j-load] + value);
            }
        }   
        return dp[capacity];
    }
};
