// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    string reverseSubString(string s, int i, int j) {
        int temp;
        while (i < j) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return s;
    }
    string reverseParentheses(string s) {
        stack<int> leftIndices;
        for (int i{}; i < s.size(); i++) {
            if (s[i] == '(') {
                leftIndices.push(i);
            } else if (s[i] == ')') {
                s = reverseSubString(s, leftIndices.top() + 1, i - 1);
                leftIndices.pop();
            }
        }

        string ans;
        for (char c : s) {
            if (c != '(' && c != ')') {
                ans.push_back(c);
            }
        }
        return ans;
    }
};

// Optimized: Wormhole Teleportation technique
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openBracketIndices;
        unordered_map<int, int> door;

        for (int i{}; i < s.size(); i++) {
            if (s[i] == '(') {
                openBracketIndices.push(i);
            } else if (s[i] == ')') {
                door[i] = openBracketIndices.top();
                door[openBracketIndices.top()] = i;
                openBracketIndices.pop();
            }
        }

        int flag = 1;
        string result;
        for (int i{}; i < s.size(); i += flag) {
            if (s[i] == '(' || s[i] == ')') {
                i = door[i];
                flag = -flag;
            } else {
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
};