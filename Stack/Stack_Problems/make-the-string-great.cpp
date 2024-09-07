// https://leetcode.com/problems/make-the-string-great/

class Solution {
public:
    string makeGood(string s) {
        if (s.size() == 0) return s;
        stack<char> st;
        st.push(s[0]);

        for (int i = 1; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            if (isupper(s[i]) && tolower(s[i]) == st.top()) {
                st.pop();
            } else if (isupper(st.top()) && tolower(st.top()) == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string ans(st.size(), ' ');
        int k = st.size() - 1;
        while (!st.empty()) {
            ans[k] = st.top();
            st.pop();
            k--;
        }
        return ans;
    }
};