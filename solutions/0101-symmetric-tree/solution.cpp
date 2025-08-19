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
    bool preorder(TreeNode* a,TreeNode* b){
        if(!a and !b) return true;
        if(!a or !b) return false;
        if(a->val!=b->val) return false;
        bool ar = preorder(a->left,b->right);
        bool br = preorder(a->right,b->left);
        return ar&br;
    }
    bool isSymmetric(TreeNode* root) {
        return preorder(root->left,root->right);
    }
};
