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
    int max_sum;
    void solve(TreeNode* root){
        if(!root)return;
        solve(root->left);
        solve(root->right);
        // if any child is negative , do not include it
        int result = root->val;
        if(root->left and root->left->val>0){
            result+=root->left->val;
        }
        if(root->right and root->right->val>0){
            result+=root->right->val;
        }
        // check for maxsum achieved
        max_sum = max(max_sum,result);

        // replace the current value with the possible max sum , if parent node is in the path
        if(root->left and root->right){
             if(root->left->val>root->right->val){
                 root->val = max(root->val,root->val+root->left->val);
             }
             else{
                 root->val = max(root->val,root->val+root->right->val);
             }
        }
        else if(root->left){
            root->val = max(root->val,root->val+root->left->val);
        }
        else if(root->right){
            root->val = max(root->val,root->val+root->right->val);
        }

    }
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        solve(root);
        return max_sum;
    }
};
