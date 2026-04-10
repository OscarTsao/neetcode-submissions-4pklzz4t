class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> countT(128, 0);

        for (char c : t) countT[c]++;
        int l = 0, r = 0, resl = 0, need = t.size();
        int resLen = INT_MAX;
        

        while (r < s.size()){
            char c = s[r];
            countT[c]--;

            if (countT[c] >= 0){
                need--;
            }
            r++;

            while (need == 0){
                if (r - l < resLen){
                    resLen = r - l;
                    resl = l;
                }
                countT[s[l]]++;
                if (countT[s[l]] > 0) need++;
                l++;
            }
        }
        return resLen == INT_MAX? "" : s.substr(resl, resLen);

    }
};
