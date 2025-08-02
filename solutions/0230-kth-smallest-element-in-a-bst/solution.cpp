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
    void inorder(TreeNode* root,int& curr, int k, int& ans){
        if(!root) return;
        inorder(root->left,curr,k,ans);

        if(curr==k){
            ans = root->val;
            curr++;
            return;
        }
        curr++;

        inorder(root->right,curr,k,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int curr =1;
        int ans = 0;
        inorder(root,curr,k,ans);
        return ans;
    }
};
