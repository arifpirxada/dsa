// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head) return head;
        unordered_map<int, int> mp;

        for (int num: nums) {
            mp[num]++;
        }

        ListNode* ptr = head;
        ListNode* prev = nullptr;
        ListNode* temp;
        while (ptr) {
            if (mp.find(ptr->val) != mp.end()) {
                temp = ptr;
                if (!prev) {
                    head = head->next;
                } else {
                    prev->next = ptr->next;
                }
                ptr = ptr->next;
                delete temp;
            } else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }
};