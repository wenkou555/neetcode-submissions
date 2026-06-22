/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0, head);

        ListNode* slowPointer = &dummy;
        ListNode* fastPointer = &dummy;

        for (int i = 0; i <= n; i++)
            fastPointer = fastPointer->next;

        while (fastPointer != nullptr) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
        }

        ListNode* target = slowPointer->next;
        slowPointer->next = slowPointer->next->next;

        delete target;

        return dummy.next;

        
    }
};
