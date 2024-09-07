// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> que;
        int i;
        for (i = 1; i <= n; i++) {
            que.push(i);
        }

        while (que.size() > 1) {
            i = 0;
            while (i < k - 1) {
                que.push(que.front());
                que.pop();
                i++;
            }
            que.pop();
        }

        return que.front();
    }
};