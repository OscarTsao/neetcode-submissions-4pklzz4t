class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        vector<int> current;
        dfs(0, nums, current, results, target);
        return results;
    }
private:
    void dfs(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& results, int target){
        int n = nums.size();
        if (target == 0) {
            results.push_back(current);
            return;
        }
        if (target < 0) return;

        for (int i = index; i < n; i++){
            current.push_back(nums[i]);
            dfs(i, nums, current, results, target - nums[i]);
            current.pop_back();
        }
    }
};