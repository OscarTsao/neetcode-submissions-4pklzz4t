class Solution {
public:
    int maxProduct(vector<int>& nums) {
            int n = nums.size();
            int ans = INT_MIN;
            int preProd = 1;
            int postProd = 1;

            for (int i = 0; i < n; i++) {
                preProd = (preProd==0)? 1:preProd;
                postProd = (postProd==0)? 1:postProd;

                preProd *= nums[i];
                postProd *= nums[n-1-i];
                ans = max({ans, preProd, postProd});
            }
            return ans;
    }
};
