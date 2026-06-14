class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int prev = 0;
        int i = 0;
        int n = s.length();
        vector<string> ans;
        while (i < n) {
            if (s[i] != '#') {
                i++;
            }
            else {
                int len = stoi(s.substr(prev, i-prev));
                ans.push_back(s.substr(i+1, len));
                i += (len+1);
                prev = i;
            }
        }
        return ans;
    }
};
