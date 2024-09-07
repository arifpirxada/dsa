// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/solutions/769698/python-clear-explanation-powerful-ultimate-binary-search-template-solved-many-problems    

class Solution {
private:
    bool possible(int capacity, vector<int>& weights, int d) {
        int currSum = 0, days = 1;
        for (int weight : weights) {
            currSum += weight;
            if (currSum > capacity) {
                days++;
                currSum = weight;
                if (days > d) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0, maxi = INT_MIN;

        for (int weight : weights) {
            maxi = max(maxi, weight);
            sum += weight;
        }
        int low = maxi, high = sum, mid;

        while (low <= high) {
            mid = (low + high) / 2;
            if (possible(mid, weights, days)) {
               high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};