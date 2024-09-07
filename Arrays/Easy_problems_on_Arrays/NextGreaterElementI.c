// https://leetcode.com/problems/next-greater-element-i/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int i, j, k;
    *returnSize = 0;
    int *ans = (int *)malloc(nums1Size * sizeof(int));

    for (i = 0; i < nums1Size; i++) {
        for (j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                if (j + 1 == nums2Size) {
                    ans[*returnSize] = -1;
                    (*returnSize)++;
                    continue;
                }
                for (k = j + 1; k <= nums2Size; k++) {
                    if (k == nums2Size) {
                        ans[*returnSize] = -1;
                        (*returnSize)++;
                        break;
                    }
                    if (nums2[j] < nums2[k]) {
                        ans[*returnSize] = nums2[k];
                        (*returnSize)++;
                        break;
                    }
                }
            }
        }
    }

    return ans;
}

// Optimized c++ approach: monotonic stack

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> mp;
        stack<int> st;

        for (int i{}; i < nums1.size(); i++) {
            mp[nums1[i]] = i;
        }

        for (int i = nums2.size() - 1; i >= 0; i--) {
            if (st.empty()) {
                st.push(nums2[i]);
            } else {
                while (!st.empty() && st.top() <= nums2[i]) {
                    st.pop();
                }
                if (!st.empty() && mp.find(nums2[i]) != mp.end()) {
                    ans[mp[nums2[i]]] = st.top();
                }
                st.push(nums2[i]);
            }
        }
        return ans;
    }
};