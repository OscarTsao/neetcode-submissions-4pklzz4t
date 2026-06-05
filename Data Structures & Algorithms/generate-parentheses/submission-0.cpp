class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int left = 0, right = 0;
        vector<string> ans;
        string cur = "";

        auto dfs = [&] (auto& self) -> void {
            if (cur.length() == 2*n) ans.push_back(cur);
            if (left < n) {
                left++;
                cur += "(";
                self(self);
                cur.pop_back();
                left--;
            }
            if (right < left) {
                right++;
                cur += ")";
                self(self);
                cur.pop_back();
                right--;
            }
        };
        dfs(dfs);
        return ans;
    }
};
