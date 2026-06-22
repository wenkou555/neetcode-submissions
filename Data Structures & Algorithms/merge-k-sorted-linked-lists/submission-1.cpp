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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* tracker = &dummy;

        while (true) {
            ListNode* minNode = nullptr;
            int minIndex = -1;

            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr)
                    continue;
                    
                if (minNode == nullptr || minNode->val > lists[i]->val) {
                    minIndex = i;
                    minNode = lists[i];
                }
            }

            if (minNode == nullptr)
                break;

            tracker->next = minNode;
            tracker = tracker->next;
            lists[minIndex] = lists[minIndex]->next;
        }

        return dummy.next;
    }
};
