class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        auto dfs = [&] (auto& self, int start, int target) -> void {
            if (target == 0) {
                ans.push_back(cur);
                return;
            }

            for (int i = start; i < n; i++) {
                if (candidates[i] > target) break;
                if (i > start && candidates[i] == candidates[i-1]) continue;
                cur.push_back(candidates[i]);
                self(self, i+1, target-candidates[i]);
                cur.pop_back();
            }
        };
        dfs(dfs, 0, target);
        return ans;
    }
};
