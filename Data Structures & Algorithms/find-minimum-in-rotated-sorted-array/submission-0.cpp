class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r){
            int pivot = (l + r) / 2;

            if (nums[pivot] < nums[r]) r = pivot;
            else l = pivot + 1;
        }
        return nums[l];
    }
};
