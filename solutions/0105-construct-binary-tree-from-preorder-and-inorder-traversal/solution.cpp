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
    TreeNode* makeTree(vector<int>& preorder,vector<int>& inorder,int left,int right,int& i){
        if(left>right){
            return nullptr;
        }    
        TreeNode* root = new TreeNode(preorder[i++]);
        int find_root = find(inorder.begin(), inorder.end(), preorder[i-1])-inorder.begin(); 
        root->left = makeTree(preorder,inorder,left,find_root-1,i);
        root->right = makeTree(preorder,inorder,find_root+1,right,i);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        return makeTree(preorder,inorder,0,preorder.size()-1,i);
    }
};
