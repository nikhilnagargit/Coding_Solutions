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
        int max_f = 0;
        int curr_f= 0;
        int curr = 0;
        vector<int> ans;

    void dfs(TreeNode* root){
        if(!root)return;
        dfs(root->left);

        if(curr==root->val){
            curr_f++;
        }
        else{
            curr = root->val;
            curr_f = 1;
        }
        if(max_f<curr_f){
                max_f = curr_f;
                ans.clear();
        }
        if(curr_f==max_f){
            ans.push_back(curr);
        }
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
