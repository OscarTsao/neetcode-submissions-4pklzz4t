class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;
        int n = words.size();

        for (const string& word: words) {
            for (const char c: word) {
                inDegree[c] = 0;
            }
        }

        for (int i = 0; i < n-1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            int len1 = w1.length();
            int len2 = w2.length();

            if (len1 > len2 && w1.substr(0, len2) == w2) {
                return "";
            }

            int minLen = min(len1, len2);
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    char u = w1[j];
                    char v = w2[j];

                    if (!adj[u].count(v)) {
                        adj[u].insert(v);
                        inDegree[v]++;
                    }
                break;
                }
            }
        }

        queue<char> q;

        for (auto& p: inDegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }

        string result = "";

        while (!q.empty()) {
            char cur = q.front();
            q.pop();

            result += cur;

            for (char neighbor: adj[cur]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if (result.length() != inDegree.size()) {
            return "";
        }
        return result;
    }
};
