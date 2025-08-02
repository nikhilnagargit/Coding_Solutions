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
    int maxi ;
    int solve(TreeNode* root){
        if(!root) return -100001;

        int left = -100001;
        if(root->left){
            left = solve(root->left);
        }
        int right = -100001;
        if(root->right){
            right = solve(root->right);
        }
        if(left<0){
            left = 0;
        }
        if(right<0){
            right =0;
        }
        maxi = max(maxi,left+right+root->val);
        return max(left+root->val,right+root->val);
    }

    int maxPathSum(TreeNode* root) {
        maxi = -100001;
        int m = solve(root);
        return maxi;
    }
};
