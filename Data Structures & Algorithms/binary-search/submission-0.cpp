class Solution {
public:
    int search(vector<int>& nums, int target) {
     int l = 0, r = nums.size() - 1;

     while (l <= r){
        int pivot = (l+r) / 2;
        if (nums[pivot] == target)
            return pivot;
        else if (nums[pivot] > target) r = pivot - 1;
        else l = pivot + 1;
     }   
     return -1;
    }
};
