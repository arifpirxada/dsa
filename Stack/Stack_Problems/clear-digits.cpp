// https://leetcode.com/problems/clear-digits/

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for (char c : s) {
            if (isdigit(c)) {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(c);
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