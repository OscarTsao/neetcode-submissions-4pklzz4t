class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> ans;

        for (auto& preCourse : prerequisites) {
            adj[preCourse[1]].push_back(preCourse[0]);
            inDegree[preCourse[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for (int course : adj[cur]) {
                inDegree[course]--;
                if (inDegree[course] == 0) {
                    q.push(course);
                }
            }
        }
        if (ans.size() == numCourses) {
            return ans;
        }
        else {
            return {};
        }
    }
};
