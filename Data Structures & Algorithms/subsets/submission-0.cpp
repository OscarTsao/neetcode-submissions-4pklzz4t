class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> current;

        dfs(0, nums, current, results);

        return results;
    }

private:
    void dfs(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& results){
        if (index == nums.size()) {
            results.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        dfs(index+1, nums, current, results);

        current.pop_back();
        dfs(index+1, nums, current, results);
    }
};
