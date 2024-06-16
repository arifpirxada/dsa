// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        vector<ListNode*> visitedNodes;
        int i;
        ListNode* ptr = head, *temp;

        while (ptr) {
            for (i = 0; i < visitedNodes.size(); i++) {
                if (ptr->next == visitedNodes[i]) {
                    return visitedNodes[i];
                }
            }
            visitedNodes.push_back(ptr);
            ptr = ptr->next;
        }

        return NULL;
    }
};