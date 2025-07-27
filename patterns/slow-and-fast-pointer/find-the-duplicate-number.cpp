// https://leetcode.com/problems/find-the-duplicate-number/

// Gives TLE
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0, j, n = nums.size();

        while (i < n) {
            j = i + 1;
            while (j < n && nums[j] != nums[i]) {
                j++;
            }
            if (nums[j] == nums[i]) return nums[i];
            i++;
        }
        return -1;
    }
};

// Slow & Fast pointer -> Floyd’s Tortoise and Hare Algorithm

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
string-compression        slow = nums[slow];
        fast = nums[nums[fast]];
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = nums[0];
        while (slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};