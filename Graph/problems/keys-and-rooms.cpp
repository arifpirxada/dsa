// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        queue<int> q;

        q.push(0);
        vis[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : rooms[node]) {
                if (!vis[neighbor]) {
                    q.push(neighbor);
                    vis[neighbor] = true;
                }
            }
        }

        for (int v : vis) {
            if (!v) return false;
        }
        return true;
    }
};