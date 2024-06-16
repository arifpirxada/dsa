#include <vector>
using namespace std;

// https://leetcode.com/problems/split-linked-list-in-parts/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int len = 0;
        ListNode* ptr = head, *prev = nullptr;

        while (ptr) {
            len++;
            ptr = ptr->next;
        }

        int n = len / k, extra = len % k;
        ptr = head;
        for (int i = 0; i < k; i++, extra--) {
            ans.push_back(ptr);
            for (int j = 0; j < n + (extra > 0); j++) {
                prev = ptr;
                ptr = ptr->next;
            }
            if (prev) {
                prev->next = nullptr;
            }
        }
        return ans;
    }
};