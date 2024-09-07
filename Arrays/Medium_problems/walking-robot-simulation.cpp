// https://leetcode.com/problems/walking-robot-simulation/

class Solution {
private:
    void updatePos(pair<int, int>& pos, int direction, bool reverse) {
        int num = 1;
        if (reverse) {
            num = -1;
        }
        if (direction == 1) {
            pos.second += num;
        } else if (direction == 2) {
            pos.first += num;
        } else if (direction == 3) {
            pos.second -= num;
        } else if (direction == 4) {
            pos.first -= num;
        }
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        pair<int, int> maxPos(0, 0);
        pair<int, int> pos(0, 0);
        unordered_map<string, int> mp;
        int direction = 1; // 1 -> N, 2 -> E, 3 -> S, 4 -> W
        long ans = 0;

        // fill obstacles to mp
        for (int i{}; i < obstacles.size(); i++) {
            string key = to_string(obstacles[i][0]) + "," + to_string(obstacles[i][1]);
            mp[key] = 1;
        }

        for (int c : commands) {
            if (c == -1) {
                direction = direction == 4 ? 1 : direction + 1;
            } else if (c == -2) {
                direction = direction == 1 ? 4 : direction - 1;
            } else {
                for (int j = 0; j < c; j++) {
                    updatePos(pos, direction, false);
                    // check obstacle
                    string key = to_string(pos.first) + "," + to_string(pos.second);
                    if (mp.find(key) != mp.end()) {
                        updatePos(pos, direction, true);
                        break;
                    }
                }
                // update max
                if ((pos.first * pos.first + pos.second * pos.second) > ans) {
                    ans = pos.first * pos.first + pos.second * pos.second;
                }
            }
        }
        return ans;
    }
};