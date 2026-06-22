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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* curNode = head;
        
        if (curNode == nullptr)
            return curNode;

        while (curNode != nullptr) {
            ListNode* tempNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = tempNode;
        }

        return prevNode;

    }
};
