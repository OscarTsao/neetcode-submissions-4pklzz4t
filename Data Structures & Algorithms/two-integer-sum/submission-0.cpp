class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> numap;

        for (int i = 0; i < n; i++){
            int diff = target - nums[i];
            if (numap.find(diff) != numap.end()){
                return {numap[diff], i};
            }
            numap.insert({nums[i], i});
        }
        return {};
    }
};
