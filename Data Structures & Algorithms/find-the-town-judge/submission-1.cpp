class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> score(n+1, 0);

        for (auto& p: trust) {
            int a = p[0];
            int b = p[1];

            score[a]--;
            score[b]++;
        }
        for (int i = 1; i <= n; i++) {
            if (score[i] == n-1) return i;
        }
        return -1;

    }
};