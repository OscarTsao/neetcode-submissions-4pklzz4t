class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        auto dfs = [&] (auto& self, int start) -> void {
            ans.push_back(cur);

            for (int i = start; i < n; i++) {
                if (i > start && nums[i] == nums[i-1]) continue;
                cur.push_back(nums[i]);
                self(self, i+1);
                cur.pop_back();
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
