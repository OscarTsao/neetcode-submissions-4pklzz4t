class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string cur = "";
        int n = digits.length();
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if (digits == "") return {};
        
        auto dfs = [&] (auto& self, int start) -> void {
            if (start > n) return;
            if (start == n) {
                ans.push_back(cur);
                return;
            }
            int num = digits[start] - '0';

            for (char c: mp[num]) {
                cur += c;
                self(self, start+1);
                cur.pop_back();
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
