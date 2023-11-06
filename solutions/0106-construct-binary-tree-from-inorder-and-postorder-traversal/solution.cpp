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
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,unordered_map<int,int>& lookup,int left,int right,int& index){
        if(left>right){
            return nullptr;
        }

        int value = postorder[index];
        TreeNode* root = new TreeNode(value);
        int index_in_inorder = lookup[value];
        index--;
        root->right = solve(inorder,postorder,lookup,index_in_inorder+1,right,index);
        root->left = solve(inorder,postorder,lookup,left,index_in_inorder-1,index);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>index_in_inorder;
        int index=postorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            index_in_inorder[inorder[i]]=i;
        }
        return solve(inorder,postorder,index_in_inorder,0,postorder.size()-1,index);
    }
};
