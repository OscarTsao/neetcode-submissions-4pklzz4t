class Solution {
private:
    unordered_set<int> visited;
    unordered_map<int, vector<int>> courses;
    
    bool dfs(int crs) {
        if (visited.count(crs)) return false;
        if (courses[crs].empty()) return true;
        visited.insert(crs);

        for (int preq: courses[crs]) {
            if (!dfs(preq)) return false;
        }    
        visited.erase(crs);
        courses[crs].clear();
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prequisites) {
        int n = prequisites.size();
        for (int i = 0; i < n; i++) {
            courses[prequisites[i][0]].push_back(prequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return false;
        }
        return true;
    }
};
