// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for (char c : s) {
            if (!st.empty()) {
                if (c == st.top()) {
                    st.pop();
                } else {
                    st.push(c);
                }
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