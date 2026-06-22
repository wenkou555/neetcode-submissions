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
            return nullptr;

        int carryOver = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;

        ListNode* resultHead = nullptr;
        ListNode* prevResNode = nullptr;

        while (cur1 != nullptr || cur2 != nullptr || carryOver != 0) {
            int val1 = (cur1 != nullptr) ? cur1->val : 0;
            int val2 = (cur2 != nullptr) ? cur2->val : 0;

            int value = val1 + val2 + carryOver;
            carryOver = value/10;
            ListNode* resNode = new ListNode(value - (carryOver * 10));
            if (resultHead == nullptr) {
                resultHead = resNode;
                prevResNode = resNode;
            } else {
                prevResNode->next = resNode;
                prevResNode = resNode;
            }

            if (cur1 != nullptr)
                cur1 = cur1->next;
            
            if (cur2 != nullptr)
                cur2 = cur2->next;
        }

        return resultHead;
        
    }
};
