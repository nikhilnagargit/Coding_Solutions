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
    Node* makeQuadTree(vector<vector<int>>& grid,int left,int right,int top,int bottom ){
        if(left==right and top==bottom){
            return new Node(grid[top][left],1);
        }
        Node* root = new Node(1,0);
        int xmid = left+(right-left)/2;
        int ymid = top+(bottom-top)/2;
        root->topLeft = makeQuadTree(grid,left,xmid,top,ymid);
        root->topRight = makeQuadTree(grid,xmid+1,right,top,ymid);
        root->bottomLeft = makeQuadTree(grid,left,xmid,ymid+1,bottom);
        root->bottomRight = makeQuadTree(grid,xmid+1,right,ymid+1,bottom);
        if(root->topLeft->val==root->topRight->val and root->bottomLeft->val==root->bottomRight->val and root->topLeft->val==root->bottomLeft->val and root->topLeft->isLeaf and root->topRight->isLeaf and root->bottomLeft->isLeaf and root->bottomRight->isLeaf){
            if(root->topLeft->val==0){
                return new Node(0,1);
            }
            return new Node(1,1);
        }
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return makeQuadTree(grid,0,n-1,0,n-1);
    }
};
