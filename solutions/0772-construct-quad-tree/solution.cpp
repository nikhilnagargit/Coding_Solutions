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

    Node* solve(vector<vector<int>>&grid,int I,int J,int N,int M){
        cout<<"I,J,N,M"<<I<<","<<J<<","<<N<<","<<M<<endl;
        // check if all are one or all are zero
        Node* node;
        int val = grid[I][J];
        bool allSame = true;
        for(int i=I;i<=N;i++ ){
            for(int j=J;j<=M;j++){
                if(grid[i][j]!=val){
                    allSame = false;
                    break;
                }
            }if(!allSame) break;
        }

        if(allSame){
            node = new Node(val,true);
        }
        else{
            node = new Node(1,false);
            node->topLeft =  solve(grid,I,J,I+(N-I)/2,J+(M-J)/2);
            node->topRight = solve(grid,I,J+(M-J)/2+1,I+(N-I)/2,M);
            node->bottomLeft = solve(grid,I+(N-I)/2+1,J,N,J+(M-J)/2);
            node->bottomRight = solve(grid,I+(N-I)/2+1,J+(M-J)/2+1,N,M);
        }
        return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(grid,0,0,n-1,n-1);
    }
};
