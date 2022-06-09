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
    Node* _newNode[2];
public:
    Node* helper(vector<vector<int>>& grid, int row, int col, int size)
    {
        if(size==1)
            return _newNode[grid[row][col]];
        size=size/2;
        // 4 size becomes 2,1,0 due to early divide and then sum
        Node* tl=helper(grid, row, col, size);
        Node* tr=helper(grid, row, col+size, size);
        Node* bl=helper(grid, row+size, col, size);
        Node* br=helper(grid, row+size, col+size, size);
        if(tl==tr && bl==br && tl==bl)
            return tl;
        return new Node(false, false, tl, tr, bl, br);
    }
    Node* construct(vector<vector<int>>& grid) {
        // edge nodes can be either of two cases
        // time reduced to create new nodes
        _newNode[0]=new Node(false, true);
        _newNode[1]=new Node(true, true);
        return helper(grid, 0, 0, grid.size());
    }
    
};