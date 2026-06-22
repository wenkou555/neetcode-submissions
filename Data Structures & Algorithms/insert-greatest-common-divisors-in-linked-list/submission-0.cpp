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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        if (!head || !head->next) return head;
        
        ListNode* curr = head;
        
        while (curr != nullptr && curr->next != nullptr) {
            ListNode* nxt = curr->next;
            
            // 1. Calculate the GCD using the C++17 STL cheat code
            int gcd_val = std::gcd(curr->val, nxt->val);
            
            // 2. Create the new node
            ListNode* gcd_node = new ListNode(gcd_val);
            
            // 3. Wire it into the list
            curr->next = gcd_node;
            gcd_node->next = nxt;
            
            // 4. Jump across the newly inserted node to continue the loop
            curr = nxt;
        }
        
        return head;
    }
};