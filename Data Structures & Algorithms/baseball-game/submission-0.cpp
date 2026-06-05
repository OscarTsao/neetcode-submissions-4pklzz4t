class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        int sum = 0;

        for (string s: operations) {
            if (s == "C") score.pop_back();
            else if (s == "D") score.push_back(2*score.back());
            else if (s == "+") {
                int n = score.size();
                score.push_back(score[n-1] + score[n-2]);
            }
            else score.push_back(stoi(s));
        }
        for (int x: score) {
            sum += x;
        }
        return sum;
    }
};