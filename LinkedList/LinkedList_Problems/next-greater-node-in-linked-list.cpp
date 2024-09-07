// https://leetcode.com/problems/next-greater-node-in-linked-list/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int size = 0;
        stack<int> st;
        // Reverse list
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            size++;
        }
        head = prev;
        vector<int> ans(size);

        // Now find previous greater element;
        curr = head;
        int k = size - 1;
        while (curr) {
            while (!st.empty() && st.top() <= curr->val) {
                st.pop();
            }
            if (st.empty()) {
                ans[k] = 0;
            } else {
                ans[k] = st.top();
            }
            st.push(curr->val);
            curr = curr->next;
            k--;
        }
        return ans;
    }
};