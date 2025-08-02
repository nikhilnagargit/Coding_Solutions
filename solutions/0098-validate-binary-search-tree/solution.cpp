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
    long maxi(long a,long b){
        if(a>b) return a;
        return b;
    }
    long mini(long a,long b){
        if(a>b) return b;
        return a;
    }
    long find_biggest(TreeNode* root){
        if(!root) return LONG_MIN;
        return maxi(root->val,maxi(find_biggest(root->left),find_biggest(root->right)));
    }
    long find_smallest(TreeNode* root){
        if(!root) return LONG_MAX;
        return mini(root->val,mini(find_smallest(root->left),find_smallest(root->right)));
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        long maxleft = find_biggest(root->left);
        if(root->val <= maxleft) return false;
        long minright = find_smallest(root->right);
        if(root->val >= minright) return false;
        return isValidBST(root->left) and isValidBST(root->right);
    }
};
