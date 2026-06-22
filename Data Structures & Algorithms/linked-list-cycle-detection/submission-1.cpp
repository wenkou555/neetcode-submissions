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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        // Only need to check 'fast' (because it runs ahead)
        // Check fast AND fast->next to ensure fast->next->next is safe
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move 1
            fast = fast->next->next;    // Move 2
            
            if (slow == fast) {         // Crash!
                return true;
            }
        }
        return false;
    }
};
