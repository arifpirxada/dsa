// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next) return {-1, -1};
        int firstLocal = -1, lastLocal = -1, prevLocal = -1, position = 1;
        ListNode* ptr = head->next, *backPtr = head;
        ListNode* frontPtr = ptr->next;
        vector<int> ans(2, INT_MAX);

        while (ptr) {
            if (backPtr->val < ptr->val && frontPtr && frontPtr->val < ptr->val) {
                if (firstLocal == -1) {
                    firstLocal = position;
                }
                if (prevLocal != -1 && ans[0] > position - prevLocal) {
                    ans[0] = position - prevLocal;
                }
                lastLocal = position;
                prevLocal = position;
            } else if (backPtr->val > ptr->val && frontPtr && frontPtr->val > ptr->val) {
                if (firstLocal == -1) {
                    firstLocal = position;
                }
                if (prevLocal != -1 && ans[0] > position - prevLocal) {
                    ans[0] = position - prevLocal;
                }
                lastLocal = position;
                prevLocal = position;
            }
            backPtr = ptr;
            ptr = frontPtr;
            frontPtr = frontPtr? frontPtr->next : nullptr;
            position++;
        }

        ans[1] = lastLocal - firstLocal;
        if (lastLocal == -1 || ans[1] < 1) {
            ans[1] = -1;
        }
        if (ans[0] == INT_MAX) {
            ans[0] = -1;
        }
        return ans;
    }
};