class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (m < n) {
            return false;
        }
        array<int, 26> freq1 = {0};
        array<int, 26> freq2 = {0};

        for (int i = 0; i < n; i++) {
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        if (freq1 == freq2) {
            return true;
        }
        for (int i = 0; i < m-n; i++) {
            freq2[s2[i]-'a']--;
            freq2[s2[n+i]-'a']++;
            if (freq1 == freq2) {
                return true;
            }        
        }
        return false;
    }
};
