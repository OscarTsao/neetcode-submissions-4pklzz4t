class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 0, count = 1;

        for (int i = 0; i < nums.size(); i++){
            if (nums[write] != nums[i]){
                write++;
                count++;
                nums[write] = nums[i];
            }
        }
        return count;
    }
};