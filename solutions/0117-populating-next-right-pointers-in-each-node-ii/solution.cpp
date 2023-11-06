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
    Node* connect(Node* root) {
        Node* marker = nullptr;
        queue<Node*> q;
        q.push(root);
        q.push(marker);
        Node* curr = q.front();
         q.pop();

        while(!q.empty()){

            if(curr==marker){
                q.push(marker);
            }
            else{
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            Node* curr2 = q.front();
            q.pop();
            if(curr==marker and curr2==marker){
                break;
            }
            if(curr2==marker){
                curr->next = nullptr;
                q.push(marker);
                curr = q.front();
                q.pop();
            }
            else{
                curr->next = curr2;
                curr = curr2;
            }
            
        }
        return root;
    }
};
