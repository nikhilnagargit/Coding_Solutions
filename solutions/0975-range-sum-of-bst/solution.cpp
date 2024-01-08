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
    int sum;
    void inorder(TreeNode* root,int low,int high,int flag){
        if(!root)return;
        if(root->val>=low and root->val<=high){
            sum+=root->val;
        }
        inorder(root->left,low,high,flag);
        inorder(root->right,low,high,flag);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        inorder(root,low,high,0);
        return sum;
    }
};
