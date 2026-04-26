// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class Solution {
public:
    void dfs(int index, vector<vector<int>>& stones, vector<bool>& vis, int n) {
        vis[index] = true;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            if (stones[index][0] == stones[i][0] || stones[index][1] == stones[i][1]) {
                dfs(i, stones, vis, n);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n, false);

        int group = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            dfs(i, stones, vis, n);
            group++;
        }

        return n - group;
    }
};