class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> steps(n, 0);
        if (n == 1) return 0;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i] && i+j < n; j++) {
                if (steps[i+j]) steps[i+j] = min(steps[i+j], steps[i]+1);
                else steps[i+j] = steps[i]+1;
            }
        }
        return steps[n-1];
    }
};
