class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        int l = 0;
        int r = n-1;

        while (l < r) {
            int area = (min(heights[l], heights[r]) * (r-l));
            ans = max(ans, area);
            if (heights[l] > heights[r]) {
                r--;
            }
            else {
                l++;
            }
        }
        return ans;
    }
};
