// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, currDepth = 0;

        for (char c : s) {
            if (c == '(') {
                currDepth++;
                depth = max(currDepth, depth);
            } else if (c == ')') {
                currDepth--;
            }
        }
        return depth;
    }
};