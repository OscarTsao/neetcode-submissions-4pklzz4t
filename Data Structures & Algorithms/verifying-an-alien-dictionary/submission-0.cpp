class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> alphabet(26, 0);
        for (int i = 0; i < 26; i++) {
            alphabet[order[i]-'a'] = i;
        }

        int n = words.size();

        for (int i = 0; i < n-1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            
            int m = min(w1.length(), w2.length());
            bool sorted_by_order = false;

            for (int j = 0; j < m; j++) {
                if (w1[j] != w2[j]) {
                    if (alphabet[w1[j]-'a'] > alphabet[w2[j]-'a']) {
                        return false;
                    }
                    sorted_by_order = true;
                    break;
                }
            }
            if (!sorted_by_order && w1.length() > w2.length()) {
                return false;
            }
        }
        return true;
    }
};