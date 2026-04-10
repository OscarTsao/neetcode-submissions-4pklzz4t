class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 0;

        for (int i = 0; i < nums.size(); i++){
            if (nums[write] != nums[i]){
                write++;
                nums[write] = nums[i];
            }
        }
        return write+1;
    }
};