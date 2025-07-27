// https://leetcode.com/problems/swap-adjacent-in-lr-string

class Solution {
public:
    bool canTransform(string start, string end) {
        string startFiltered, endFiltered;
        for (char c : start) {
            if (c != 'X')
                startFiltered += c;
        }
        for (char c : end) {
            if (c != 'X')
                endFiltered += c;
        }

        if (startFiltered != endFiltered)
            return false;

        int i = 0, j = 0;
        int n = start.size();
        while (i < n && j < n) {
            while (i < n && start[i] == 'X')
                i++;
            while (j < n && end[j] == 'X')
                j++;

            if (i >= n || j >= n)
                break;

            if (start[i] != end[j])
                return false;

            if (start[i] == 'L' && i < j)
                return false;
            if (start[i] == 'R' && i > j)
                return false;

            i++;
            j++;
        }

        return true;
    }
};