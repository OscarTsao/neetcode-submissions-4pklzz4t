class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        vector<int> current;
        sort(nums.begin(), nums.end());
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

        for (int i = index; i < n; i++){
            if (nums[i] > target) break;
            current.push_back(nums[i]);
            dfs(i, nums, current, results, target - nums[i]);
            current.pop_back();
        }
    }
};