/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        // Start the recursion covering the entire grid (0, 0) with the full length
        return build(grid, 0, 0, grid.size());
    }

private:
    Node* build(const vector<vector<int>>& grid, int r, int c, int length) {
        // Step 1: Check if this entire square is uniform
        if (isUniform(grid, r, c, length)) {
            // It's uniform! Make a leaf node. 
            // grid[r][c] == 1 evaluates to true for 1s, false for 0s.
            return new Node(grid[r][c] == 1, true);
        }

        // Step 2: It's mixed. We must divide and conquer.
        int half = length / 2;
        
        // Recursively build the 4 quadrants
        Node* topLeft = build(grid, r, c, half);
        Node* topRight = build(grid, r, c + half, half);
        Node* bottomLeft = build(grid, r + half, c, half);
        Node* bottomRight = build(grid, r + half, c + half, half);

        // Step 3: Create the parent node connecting them.
        // The problem states 'val' can be anything for a non-leaf node, so we arbitrarily pass true.
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    // Helper function to check if the square from (r, c) of size 'length' is all 1s or all 0s
    bool isUniform(const vector<vector<int>>& grid, int r, int c, int length) {
        int firstVal = grid[r][c];
        for (int i = r; i < r + length; i++) {
            for (int j = c; j < c + length; j++) {
                if (grid[i][j] != firstVal) {
                    return false; // Found a mismatch
                }
            }
        }
        return true; // Everything matched
    }
};