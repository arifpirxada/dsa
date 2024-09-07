// https://leetcode.com/problems/sum-of-subarray-minimums/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n), pse(n, -1);
        stack<int> st, st2;
        int M = 1e9 + 7;
        long long ans = 0, subarrays;

        // find nse
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }

        // find pse
        for (int i = 0; i < n; i++) {
            while (!st2.empty() && arr[st2.top()] > arr[i]) {
                st2.pop();
            }

            if (!st2.empty()) {
                pse[i] = st2.top();
            }
            st2.push(i);
        }

        for (int i{}; i < n; i++) {
            subarrays = (i - pse[i]) * (nse[i] - i);
            ans = (ans + arr[i] * subarrays) % M;
        }

        return ans;
    }
};