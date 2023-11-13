/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool doescontainanyvalue(TreeNode* root,int p,int q){
        if(!root)return false;
        if(root->val==p or root->val==q){
            return true;
        }
        if(root->left==nullptr and root->right==nullptr){
            return false;
        }
         return doescontainanyvalue(root->left,p,q) or doescontainanyvalue(root->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;
        if(root->val==p->val or root->val==q->val){
            return root;
        }
        bool isright = doescontainanyvalue(root->right,p->val,q->val);
        bool isleft = doescontainanyvalue(root->left,p->val,q->val);
        if(isright and isleft) return root;
        if(isright) return lowestCommonAncestor(root->right,p,q);
        if(isleft) return lowestCommonAncestor(root->left,p,q);
        return nullptr;
    }
};
