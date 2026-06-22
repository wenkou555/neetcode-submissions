/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> nodeCache({{NULL, NULL}});
        Node dummyNode = Node(-1);
        Node* trackerNode = &dummyNode;
        Node* originalNode = head;
        while (originalNode != NULL) {
            Node* newNode = new Node(originalNode->val);
            trackerNode->next = newNode;
            nodeCache[originalNode] = newNode;
            trackerNode = trackerNode->next;
            originalNode = originalNode->next;
        }


        trackerNode = dummyNode.next;
        originalNode = head;
        while(trackerNode != NULL) {
            trackerNode->random = nodeCache[originalNode->random];
            trackerNode = trackerNode->next;
            originalNode = originalNode->next;
        }

        return dummyNode.next;
        
    }
};
