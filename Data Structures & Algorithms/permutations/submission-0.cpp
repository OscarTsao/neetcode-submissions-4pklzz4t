class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = nums.size();
        vector<bool> used(n, false);

        auto dfs = [&] (auto& self) -> void {
            if (cur.size() == n) ans.push_back(cur);

            for (int i = 0; i < n; i++) {
                if (used[i]) continue;
                cur.push_back(nums[i]);
                used[i] = true;
                self(self);
                cur.pop_back();
                used[i] = false;
            }
        };
        dfs(dfs);
        return ans;
        
    }
};
