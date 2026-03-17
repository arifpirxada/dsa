// My

class Solution {
public:
    int ans;
    bool canEat(vector<int>& piles, int h, int count) {
        if (count == 0) return false;
        for (int i = 0; i < piles.size(); i++) {
            int element = piles[i];
            h -= element / count;
            if (element % count != 0) h--;
            if (h < 0) return false;
        }
        return true;
    }
    void bs(vector<int>& piles, int h) {
        ans = *max_element(piles.begin(), piles.end());
        int l = 0, r = ans;
        int mid;

        while (l <= r) {
            mid = l + (r - l) / 2;

            if (canEat(piles, h, mid)) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        bs(piles, h);

        return ans;
    }
};

// Gpt

class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k) {
        long long hours = 0;

        for (int p : piles) {
            hours += (p + k - 1) / k;   // ceil(p / k)

            if (hours > h) return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canEat(piles, h, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};