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

    void inorder(TreeNode* root,vector<TreeNode*>& arr){
        if(!root){
            return;
        }
        if(root->left){
                inorder(root->left,arr);
        }
        arr.push_back(root);
        if(root->right){
            inorder(root->right,arr);
        }
    }

    TreeNode* constructBalancesBst(vector<TreeNode*>&arr,int left,int right){
        if(left>right){
            return nullptr;
        }
        int mid = right-(right-left)/2;

        TreeNode* curr = new TreeNode();
        curr->val = arr[mid]->val;
        curr->left = constructBalancesBst(arr,left,mid-1);
        curr->right = constructBalancesBst(arr,mid+1,right);
        return curr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> arr;
        inorder(root,arr);
        TreeNode* newRoot = constructBalancesBst(arr,0,arr.size()-1);
        return newRoot;
    }
};
