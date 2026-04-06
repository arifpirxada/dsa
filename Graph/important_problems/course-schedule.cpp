// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool isCycleDFS(int node, vector<vector<int>>& pre, vector<bool>& vis, vector<bool>& recPath) {
        vis[node] = true;
        recPath[node] = true;

        for (int i = 0; i < pre.size(); i++) {
            int v = pre[i][0];
            int u = pre[i][1];

            if (u != node) continue;

            if (!vis[v]) {
                if (isCycleDFS(v, pre, vis, recPath)) {
                    return true;
                }
            } else if (recPath[v]) {
                return true;
            }
        }

        recPath[node] = false;
        return false;        
    }
    bool isCycle(int numCourses, vector<vector<int>>& pre) {
        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {                
                if (isCycleDFS(i, pre, vis, recPath)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return !isCycle(numCourses, prerequisites);
    }
};