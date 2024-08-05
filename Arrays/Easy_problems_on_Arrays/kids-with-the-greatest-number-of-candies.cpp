// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size(), maxi = INT_MIN;
        vector<bool> result(n, false);

        for (int i = 0; i < n; i++) {
            maxi = max(candies[i], maxi);
        }

        for (int i = 0; i < n; i++) {
            if (candies[i] + extraCandies >= maxi) {
                result[i] = true;
            }
        }

        return result;
    }
};