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

    
    bool isValidBST(TreeNode* root, long long int min = LLONG_MIN, long long int max = LLONG_MAX) {
        if(root == nullptr){
		    return true; 
	    }
        
        if(min < root->val && max > root->val && isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max)){
            return true;
        }
        
        return false;
    }
};
