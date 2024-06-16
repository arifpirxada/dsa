// https://leetcode.com/problems/build-an-array-with-stack-operations/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> st;
        int i = 1, j = 0;
        while (i <= n && j < target.size()) {
            st.push(i);
            ans.push_back("Push");

            if (st.top() != target[j]) {
                st.pop();
                ans.push_back("Pop");
                j--;
            }
            j++;
            i++;
        }
        return ans;
    }
};