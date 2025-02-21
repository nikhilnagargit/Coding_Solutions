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
class FindElements {
public:
    unordered_set<int> myset;

    void dfs(TreeNode* root,int nextValue){
        if(!root){
            return;
        }
        root->val = nextValue;
        myset.insert(nextValue);
        dfs(root->left,nextValue*2 + 1);
        dfs(root->right,nextValue*2 + 2);
    }

    FindElements(TreeNode* root) {
        dfs(root,0);
    }
    
    bool find(int target) {
        return myset.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
