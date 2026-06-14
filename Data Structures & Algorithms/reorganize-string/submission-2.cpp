class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        array<int, 26> freq = {0};
        for (char c : s ) {
            freq[c-'a']++;
        }
        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                maxHeap.push({freq[i], 'a'+i});
            }
        }
        if (maxHeap.top().first > (n+1) / 2) {
            return "";
        }
        pair<int, char> prev = {0, '#'};
        string ans = "";

        while (!maxHeap.empty()) {
            pair<int, char> cur = maxHeap.top();
            maxHeap.pop();
            ans += cur.second;
            cur.first--;
            if (prev.first > 0) {
                maxHeap.push(prev);
            }
            prev = cur;
        }
        return ans;
    }
};