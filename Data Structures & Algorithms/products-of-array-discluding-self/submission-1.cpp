class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suff(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                pre[i] = 1;
                suff[n-1-i] = 1;
            }
            else {
                pre[i] = pre[i-1] * nums[i-1];
                suff[n-i-1] = suff[n-i] * nums[n-i];
            }
        }
        vector<int> ans(n);
        for (int i = 0; i<n; i++) {
            ans[i] = pre[i]*suff[i];
        }
        return ans;
    }
};
