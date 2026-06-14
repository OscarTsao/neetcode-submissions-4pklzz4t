class Solution {
public:
    string simplifyPath(string path) {
        vector<string> data;
        stringstream ss(path);
        string s = "";

        while (getline(ss, s, '/')) {
            if (s == "" || s == ".") {
                continue;
            }
            else if (s == "..") {
                if (!data.empty()) {
                    data.pop_back();
                }
            }
            else {
                data.push_back(s);
            }
        }
        string ans = "";
        for (const string& s : data) {
            ans += ('/' + s);
        }
        return (ans=="")? "/":ans;
    }
};