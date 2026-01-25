/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root or root==p or root==q){
            return root;
        }
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        if(rightAns and leftAns){
            return root;
        }
        if(rightAns) return rightAns;
        if(leftAns) return leftAns;
        return nullptr;
    }
};
