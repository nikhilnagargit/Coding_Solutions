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

    void inorder(TreeNode* root,map<int,unordered_set<int>>& mapping){
        if(!root){
            return;
        }
        if(root->left){
            mapping[root->val].insert(root->left->val);
            inorder(root->left,mapping);
     
        }
        if(root->right){
            mapping[root->val].insert(root->right->val);
            inorder(root->right,mapping);
        }
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        if(root1 and !root2){
            return false;
        }
        if(!root1 and root2){
            return false;
        }

        map<int,unordered_set<int>> mapping1;
        map<int,unordered_set<int>> mapping2;

        inorder(root1,mapping1);   
        inorder(root2,mapping2); 

        if(mapping1==mapping2){
            return true;
        }  
        return false;
    }
};
