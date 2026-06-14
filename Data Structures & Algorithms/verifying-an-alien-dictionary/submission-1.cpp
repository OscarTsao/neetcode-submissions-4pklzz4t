class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        int n = words.size();
        for (int i = 0; i < 26; i++) {
            mp[order[i]] = i;
        }
        for (int i = 0; i < n-1; i++) {
            int len = min(words[i].length(), words[i+1].length());
            bool correct = false;
            for (int j = 0; j < len; j++) {
                if (words[i][j] != words[i+1][j]) {
                    if (mp[words[i][j]] > mp[words[i+1][j]]) {
                        return false;
                    }
                    else {
                       correct = true; 
                       break;
                    }
                }
            }
            if (!correct) {
                if (words[i].length() > words[i+1].length()) {
                    return false;
                }
            }
        }
        return true;
    }
};