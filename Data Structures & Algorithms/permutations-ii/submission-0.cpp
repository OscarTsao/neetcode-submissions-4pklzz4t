class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> used(n, false);

        sort(nums.begin(), nums.end());

        auto backtracking = [&] (auto& self, int start) -> void {
            if (start == n) {
                ans.push_back(cur);
                return;
            }
            for (int i = 0; i < n; ++i) {
                if (used[i]) continue;
                if (i > 0 && nums[i] == nums[i-1] && used[i-1]) continue;
                
                cur.push_back(nums[i]);
                used[i] = true;;
                self(self, start+1);
                cur.pop_back();
                used[i] = false;
            }
        };
        backtracking(backtracking, 0);
        return ans;
    }
};