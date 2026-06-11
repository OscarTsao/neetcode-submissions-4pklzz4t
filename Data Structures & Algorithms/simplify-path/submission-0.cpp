class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string dir;

        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") {
                continue;
            }
            else if (dir == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            }
            else {
                st.push_back(dir);
            }
        }

        if (st.empty()) {
            return "/";
        }
        
        string res = "";
        for (string& s : st) {
            res += ('/' + s);
        }
        return res;
    }
};