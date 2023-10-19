/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int inorder(TreeNode* root){
        if(root==NULL){
            return 0 ;
        }
        int d1 = 0 ;

            d1 = inorder(root->left);
        
        int d2= 0;

           d2= inorder(root->right);

        return 1+max(d1,d2);
    }
    int maxDepth(TreeNode* root) {
        return inorder(root);
    }
};
