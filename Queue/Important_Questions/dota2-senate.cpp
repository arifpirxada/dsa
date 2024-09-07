// https://leetcode.com/problems/dota2-senate/

class Solution {
public:
    string predictPartyVictory(string senate) {
        int killRad = 0, killDire = 0, radSum = 0, direSum = 0;
        queue<int> que;

        for (int i{}; i < senate.size(); i++) {
            if (senate[i] == 'R') {
                radSum++;
            } else {
                direSum++;
            }
            que.push(senate[i]);
        }

        while (radSum != 0 && direSum != 0) {
            if (que.front() == 'R') {
                if (killRad > 0) {
                    que.pop();
                    killRad--;
                    radSum--;
                } else {
                    killDire++;
                    que.push(que.front());
                    que.pop();
                }
            } else {
                if (killDire > 0) {
                    que.pop();
                    killDire--;
                    direSum--;
                } else {
                    killRad++;
                    que.push(que.front());
                    que.pop();
                }
            }
        }

        if (radSum == 0) {
            return "Dire";
        }
        return "Radiant";
    }
};