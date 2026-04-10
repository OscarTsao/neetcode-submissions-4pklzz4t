class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, maxSum = nums[0];

        for (int i : nums){
            if (curSum < 0) curSum = 0;
            curSum += i;
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
