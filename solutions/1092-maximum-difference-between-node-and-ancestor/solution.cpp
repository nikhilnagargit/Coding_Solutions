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
    void solve(TreeNode* root,int maxvalue, int minvalue, int& maxdiff){
        if(!root)return;
        maxdiff = max(maxdiff,max(abs(root->val-maxvalue),abs(root->val-minvalue)));
        minvalue = min(minvalue,root->val);
        maxvalue = max(maxvalue,root->val);
        solve(root->left,maxvalue,minvalue,maxdiff);
        solve(root->right,maxvalue,minvalue,maxdiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int maxvalue = root->val;
        int minvalue = root->val;
        int maxdiff = 0;
        solve(root,maxvalue,minvalue,maxdiff);
        return maxdiff;
    }
};
