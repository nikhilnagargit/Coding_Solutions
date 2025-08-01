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
    TreeNode* solve(TreeNode* root){
        if(!root) return root;
        
        if(root->left and root->right){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            TreeNode* rightend = solve(right);
            TreeNode* leftend = solve(left);
            root->right = left;
            leftend->right = right;
            root->left = nullptr;
            return rightend;
        }

        if(root->left){
            root->right = root->left;
            TreeNode* leftend = solve(root->left);
            root->left = nullptr;
            return leftend;
        }

        if(root->right){
            TreeNode* rightend = solve(root->right);
            return rightend;
        }

        return root;
    }

    void flatten(TreeNode* root) {
        TreeNode* x =  solve(root);
    }
};
