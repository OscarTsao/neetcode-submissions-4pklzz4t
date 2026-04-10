class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), suffix(n), result(n);

        for (int i = 0; i < n; i++){
            if (i == 0){
                prefix[i] = 1;
                suffix[n-1-i] = 1;
            }
            else{
                prefix[i] = prefix[i-1] * nums[i-1];
                suffix[n-1-i] = suffix[n-i] * nums[n-i];
            }
        }
        for (int i = 0; i < n; i++){
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};
