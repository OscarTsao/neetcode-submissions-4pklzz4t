class Solution {
private:
    int expand(string& s, int l, int r) {
        int n = s.length();
        int count = 0;

        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
            count++;
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            count += expand(s, i, i);
            count += expand(s, i, i+1);
        }
        return count;
    }
};
