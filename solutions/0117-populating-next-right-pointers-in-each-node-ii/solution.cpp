/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // will accept parent node as argument
    Node* find_next(Node* cur){
       while(cur){
            if(cur->left){
                
                return cur->left;
            }
             else if(cur->right){
                return cur->right;
            }
            cur=cur->next;
        }
        return NULL;
    }


    Node* connect(Node* root) {
        if(!root) return root;
        if(root->left){
            if(root->right)
                root->left->next = root->right;
            else
            {
                Node* cur = root->next;
                root->left->next = find_next(cur);
            }
        }
        if(root->next){
            if(root->right){    
                Node* cur = root->next;
                 root->right->next = find_next(cur);       
            }
        }
        connect(root->right);
        connect(root->left);
        return root;
    }


};
