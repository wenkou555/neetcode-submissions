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
    bool hasCycle(ListNode* head) {
        if (head == nullptr)
            return false;

        ListNode* slowNode = head->next;
        if (slowNode == nullptr)
            return false;

        ListNode* fastNode = slowNode->next;
        while (fastNode != nullptr && slowNode != nullptr) {
            if (fastNode == slowNode)
                return true;
            
            if (fastNode->next == nullptr)
                return false;

            slowNode = slowNode->next;

            fastNode = fastNode->next->next;

        }

        return false;
    }
};
