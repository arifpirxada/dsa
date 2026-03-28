// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0, count, n = bloomDay.size();

        for (int i = 0; i < n; i++) {
            count = 0;
            while (i < n && bloomDay[i] <= day) {
                count++;
                i++;
            }
            bouquets += count / k;
        }

        return bouquets >= m;
    }
    int bs(vector<int>& bloomDay, int m, int k, int mx) {
        int low = 0, high = mx, mid;
        int days = -1;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                if (days == -1) days = mx;
                days = min(days, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return days;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mx = bloomDay[0];

        for (int d : bloomDay) {
            mx = max(mx, d);
        }

        return bs(bloomDay, m, k, mx);
    }
};

// Better written:

class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0, count = 0;

        for (int d : bloomDay) {
            if (d <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if (m * 1LL * k > n) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};