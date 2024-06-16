// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAr = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            if (height[i] > height[j]) {
                if (height[j] * (j - i) > maxAr) {
                    maxAr = height[j] * (j - i);
                }
            } else {
                if (height[i] * (j - i) > maxAr) {
                    maxAr = height[i] * (j - i);
                }
            }
            if (height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }
        return maxAr;
    }
};