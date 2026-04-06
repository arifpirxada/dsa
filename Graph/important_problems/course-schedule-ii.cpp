// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    bool topoSortDFS(int node, vector<vector<int>>& pre, vector<bool>& vis, stack<int>& st, vector<bool>& recPath) {
        vis[node] = true;
        recPath[node] = true;

        for (int i = 0; i < pre.size(); i++) {
            int v = pre[i][0];
            int u = pre[i][1];

            if (u != node) continue;

            if (!vis[v]) {
                if (topoSortDFS(v, pre, vis, st, recPath)) {
                    return true;
                }
            } else if (recPath[v]) {
                return true;
            }
        }

        recPath[node] = false;
        st.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        stack<int> st;
        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (topoSortDFS(i, prerequisites, vis, st, recPath)) {
                    return {};
                }
            }
        }

        while (!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }

        return order;
    }
};