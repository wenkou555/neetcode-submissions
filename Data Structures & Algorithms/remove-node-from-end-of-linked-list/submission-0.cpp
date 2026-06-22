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
        if (head == nullptr)
            return nullptr;

        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        for (int i = 1; i < n; i++) {
            if (fastPointer == nullptr)
                return nullptr;

            fastPointer = fastPointer->next;
        } 

        ListNode* prevPointer = nullptr;
        while (fastPointer != nullptr) {
            fastPointer = fastPointer->next;
            if (fastPointer == nullptr){
                if (prevPointer != nullptr)
                    prevPointer->next = slowPointer->next;
                else
                    head = head->next;
                delete slowPointer;
            } else {
                prevPointer = slowPointer;
                slowPointer = slowPointer->next;
            }
        }

        return (head == nullptr) ? nullptr: head;
        
    }
};
