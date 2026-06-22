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
private:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr; 
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKthNode(groupPrev, k);
            
            if (kth == nullptr) {
                break;
            }

            ListNode* groupNext = kth->next; 
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next; 
            ListNode* nextGroupPrev = curr;

            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            groupPrev->next = kth;
            groupPrev = nextGroupPrev;
        }

        return dummy.next;
    }
};
