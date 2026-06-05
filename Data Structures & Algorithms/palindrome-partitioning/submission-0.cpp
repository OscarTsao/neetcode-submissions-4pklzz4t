class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        int n = s.length();

        auto isPalindrome = [&] (auto& self, int l, int r) -> bool {
            while (l < r) {
                if (s[l] == s[r]) {
                    l++;
                    r--;
                }
                else return false;
            }
            return true;
        };

        auto dfs = [&] (auto& self, int start) -> void {
            if (start == n) ans.push_back(cur);

            for (int i = start; i < n; i++) {
                if (isPalindrome(isPalindrome, start, i)) {
                    cur.push_back(s.substr(start, i-start+1));
                    self(self, i+1);
                    cur.pop_back();
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
