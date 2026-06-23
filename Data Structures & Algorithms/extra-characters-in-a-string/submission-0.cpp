struct TrieNode {
    TrieNode* next[26];
    bool isWord = false;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    };
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        TrieNode* trie = new TrieNode();
        TrieNode* cur = trie;
        for (const string& dict : dictionary) {
            cur = trie;
            for (char c : dict) {
                if (cur->next[c-'a'] == nullptr) cur->next[c-'a'] = new TrieNode();
                cur = cur->next[c-'a'];
            }
            cur->isWord = true;
        }
        int n = s.length();
        vector<int> dp(n+1, 0);


        for (int i = n-1; i >= 0; i--) {
            cur = trie;
            dp[i] = dp[i+1] + 1;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (cur->next[idx] == nullptr) break;
                cur = cur->next[idx];

                if (cur->isWord) dp[i] = min(dp[i], dp[j+1]);
            }
        }
        return dp[0];
    }
};