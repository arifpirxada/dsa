// https://leetcode.com/problems/find-k-th-smallest-pair-distance/

// TIME LIMIT EXCEEDS =>
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> v;

        for (int i{}; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                v.push_back(abs(nums[j] - nums[i]));
            }
        }

        sort(v.begin(), v.end());
        return v[k - 1];
    }
};

// Best solution: Binary search
class Solution {
private:
    int slidingWindowCount(vector<int>& nums, int mid) {
        int i = 0, j = 0, pairCount = 0;
        while (j < nums.size()) {
            while (nums[j] - nums[i] > mid) {
                i++;
            }
            pairCount += j - i;
            j++;
        }
        return pairCount;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums[nums.size() - 1] - nums[0], mid;
        int result = 0, count = 0;

        while (low <= high) {
            mid = (low + high) / 2;

            count = slidingWindowCount(nums, mid);

            if (count < k) {
                low = mid + 1;
            } else {
                result = mid;
                high = mid - 1;
            }
        }
        return result;
    }
};