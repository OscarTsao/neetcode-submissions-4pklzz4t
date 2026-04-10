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
        int n = nums.size();
        results.push_back(current);
       
        for (int i = index; i < n; i++){
            current.push_back(nums[i]);
            dfs(i+1, nums, current, results);
            current.pop_back();
        }
    }
};
