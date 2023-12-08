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
    void inorder(TreeNode* root,string& v){
        if(!root->left and !root->right){
            v+= to_string(root->val)+"-";
            return;
        }
        if(root->left)
        inorder(root->left,v);
        if(root->right)
        inorder(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 or !root2)return false;
        string v1,v2;
        inorder(root1,v1);
        inorder(root2,v2);
        if(v1==v2){
            return true;
        }
        return false;
    }
};
