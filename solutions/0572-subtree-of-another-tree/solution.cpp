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

    bool match(TreeNode* root, TreeNode* subRoot){
        if(!root and !subRoot) return true;
        if(!root or !subRoot) return false;
        if(root->val==subRoot->val){
            return match(root->right,subRoot->right) and match(root->left,subRoot->left);
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root and !subRoot) return true;
        if(!root or !subRoot) return false;
        if(match(root,subRoot)) return true;
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};
