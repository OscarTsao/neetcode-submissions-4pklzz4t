class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;

        auto dfs = [&] (auto& self, int start, int count) -> void {
            if (count == 0) ans.push_back(cur);
            for (int i = start; i <= n; i++) {
                cur.push_back(i);
                self(self, i+1, count-1);
                cur.pop_back();
            }
        };
        dfs(dfs, 1, k);
        return ans;
    }
};