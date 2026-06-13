class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c-'a']++;
        }
        for (char c: t) {
            freq[c-'a']--;
        }
        for (int x : freq) {
            if (x) {
                return false;
            }
        }
        return true;
    }
};
