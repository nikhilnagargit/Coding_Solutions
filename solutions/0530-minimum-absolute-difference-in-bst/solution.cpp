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
    void solve(TreeNode* root,int& min_diff,int &prev){
        if(root==nullptr){
            return;
        }
        
        solve(root->left,min_diff,prev);
        if(prev!=-1){
            min_diff = min(min_diff,root->val-prev);
        }
        prev = root->val;

        solve(root->right,min_diff,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        int min_diff = INT_MAX;
        solve(root,min_diff,prev);
        return min_diff;
    }
};
