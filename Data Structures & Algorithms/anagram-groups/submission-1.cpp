class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string index = s;
            sort(index.begin(), index.end());
            mp[index].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto& p : mp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
