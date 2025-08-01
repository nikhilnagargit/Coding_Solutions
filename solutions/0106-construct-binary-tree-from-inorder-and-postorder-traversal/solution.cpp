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
    TreeNode* solve(unordered_map<int,int>&m,vector<int>&postorder,int left,int right,int& i){
        if(left>right) return nullptr;
        TreeNode* root = new TreeNode(postorder[i]);
        int mid = m[postorder[i]];
        i = i-1;
        root->right = solve(m,postorder,mid+1,right,i);
        root->left = solve(m,postorder,left,mid-1,i);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        int i=postorder.size()-1;
        return solve(m,postorder,0,inorder.size()-1,i);
    }
};
