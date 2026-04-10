class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        int max_sum = dp[0];

        for (int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
            if (dp[i] > max_sum) max_sum = dp[i];
        }
        return max_sum;
    }
};
