// https://leetcode.com/problems/removing-stars-from-a-string/

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '*') {
                st.pop();
            } else {
                st.push(c);
            }
        }

        string ans(st.size(), ' ');
        int k = st.size() - 1;
        while(!st.empty()) {
            ans[k] = st.top();
            st.pop();
            k--;
        }
        return ans;
    }
};