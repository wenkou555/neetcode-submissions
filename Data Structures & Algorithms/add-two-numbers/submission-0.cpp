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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr and l2 == nullptr)
            return 0;

        int carryOver = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;

        ListNode* resultHead = nullptr;
        ListNode* prevResNode = nullptr;

        while (cur1 != nullptr && cur2 != nullptr) {
            int value = cur1->val + cur2->val + carryOver;
            carryOver = value/10;
            ListNode* resNode = new ListNode(value - (carryOver * 10));
            if (resultHead == nullptr) {
                resultHead = resNode;
                prevResNode = resNode;
            } else {
                prevResNode->next = resNode;
                prevResNode = resNode;
            }

            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        if (cur1 == nullptr) {
            while (cur2 != nullptr) {
               int value = cur2->val + carryOver;
               carryOver = value/10; 
               ListNode* resNode = new ListNode(value - (carryOver * 10));
               prevResNode->next = resNode;
               prevResNode = resNode;
               cur2 = cur2->next;

            }
        } else if (cur2 == nullptr) {
            while (cur1 != nullptr) {
               int value = cur1->val + carryOver;
               carryOver = value/10; 
               ListNode* resNode = new ListNode(value - (carryOver * 10));
               prevResNode->next = resNode;
               prevResNode = resNode;
               cur1 = cur1->next;

            }
        }

        if (carryOver != 0) {
            ListNode* resNode = new ListNode(carryOver);
            prevResNode->next = resNode;
        }

        return resultHead;
        
    }
};
