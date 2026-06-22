/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return node;

        if (oldToNew.find(node) != oldToNew.end())
            return oldToNew[node];

        Node* newNode = new Node(node->val);
        oldToNew[node] = newNode;


        for (Node* neighborNode: node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighborNode));
        }

        return newNode;

    }

private:
    unordered_map<Node*, Node*> oldToNew;
};
