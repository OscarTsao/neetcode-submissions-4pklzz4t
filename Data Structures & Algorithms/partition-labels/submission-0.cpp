class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> end(26, 0);
        for (int i = 0; i < n; i++) {
            end[s[i]-'a'] = i;
        }

        int curEnd = 0;
        int curStart = 0;
        int i = 0;
        vector<int> ans;
        while (curEnd < n && i < n) {
            curEnd = max(curEnd, end[s[i]-'a']);
            if (i == curEnd) {
                ans.push_back(curEnd - curStart+1);
                curStart = i+1;
            }
            i++;
        }
        return ans;
    }
};
