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
    void solve(TreeNode*root,int& count,int maxvaluetillnow){
        int maxi = maxvaluetillnow;
        if(root->left){
            if(maxi<=(root->left->val)){
                count++;
                maxi = root->left->val;
            }
            solve(root->left,count,maxi);
        }
        
        if(root->right){
            if(maxvaluetillnow<=(root->right->val)){
                count++;
                maxvaluetillnow = root->right->val;
            }
            solve(root->right,count,maxvaluetillnow);
        }

    }
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        int count = 1;
        int maxvaluetillnow = root->val;
        solve(root,count,maxvaluetillnow);
        return count;
    }
};
