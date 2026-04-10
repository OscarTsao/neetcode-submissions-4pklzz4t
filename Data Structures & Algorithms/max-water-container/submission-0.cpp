class Solution {
public:
    int maxArea(vector<int>& heights) {
      int l = 0, r = heights.size() - 1;
      int area = min(heights[l], heights[r]) * (r - l);

      while (l < r){
        if (heights[l] <= heights[r]) l++;
        else r--;
        area = max(area, min(heights[l], heights[r]) * (r - l));
      }  
      return area;
    }
};
