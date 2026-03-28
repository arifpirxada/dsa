// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int i = 0, n = weights.size(), c;

        while (i < n) {
            c = capacity;
            while (i < n && c > 0 && c >= weights[i]) {
                c -= weights[i];
                i++;
            }
            days--;
            if (days < 0) return false;
        }

        return days >= 0;
    }
    int bs(vector<int>& weights, int days, int sum) {
        int low = 0, high = sum, mid;
        int ans = sum;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum;
        for (int w : weights) {
            sum += w;
        }

        return bs(weights, days, sum);
    }
};