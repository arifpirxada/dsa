// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0, high = n - 1, mid;

        while (low <= high) {
            mid = (low + high) / 2;
            if (letters[mid] == target) {
                if (mid == n - 1) return letters[0];
                if (letters[mid] == letters[n - 1] && mid != n - 1) return letters[0];
                int i = mid + 1;
                while (letters[i] == letters[mid]) {
                    i++;
                }
                return letters[i];
            } else if (letters[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (high == n - 1) return letters[0];
        if (high == n - 1 && low >= high) return letters[0];

        return letters[low];
    }
};

// short 
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0, high = n - 1, mid;

        if (target >= letters[n - 1] || target < letters[0]) {
            return letters[0];
        }

        while (low <= high) {
            mid = (low + high) / 2;
            if (target >= letters[mid]) {
                low = mid + 1;
            } 
            if (target < letters[mid]) {
                high = mid - 1;
            }
        }

        return letters[low];
    }
};