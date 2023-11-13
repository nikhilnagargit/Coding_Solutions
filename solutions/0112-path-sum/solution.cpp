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
    bool solve(TreeNode* root,int& target,int sum){
        if(root==nullptr) return false;
        if(root->left==nullptr and root->right==nullptr and root->val+sum==target){
            return true;
        }
        return solve(root->left,target,sum+root->val) or solve(root->right,target,sum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        return solve(root,targetSum,0);
    }
};
