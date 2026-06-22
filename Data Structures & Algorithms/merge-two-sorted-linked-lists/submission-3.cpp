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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prev = new ListNode();
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        ListNode* mergedListStart = prev;

        while(cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val > cur2->val) {
                prev->next = cur2;
                cur2 = cur2->next;
                prev = prev->next;
            } else {
                prev->next = cur1;
                cur1 = cur1->next;
                prev = prev->next;           
            }
        }

        if (cur1 == nullptr) {
            prev->next = cur2;
        } else if (cur2 == nullptr) {
            prev->next = cur1;
        }

        return mergedListStart->next;
        
    }
};
