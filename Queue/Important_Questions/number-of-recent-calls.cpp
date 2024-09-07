// https://leetcode.com/problems/number-of-recent-calls/

class RecentCounter {
private:
    queue<int> que;
public:
    RecentCounter() {}
    
    int ping(int t) {
        que.push(t);
        while (que.front() < t - 3000) {
            que.pop();
        }
        return que.size();
    }
};