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
    int traverse(TreeNode* root,int level,vector<int>& max_arr){
        if(root==nullptr){
            return level;
        }
        if(root->val>max_arr[level]){
            max_arr[level] = root->val;
        }
        return max(traverse(root->left,level+1,max_arr),traverse(root->right,level+1,max_arr));
    }

        
    vector<int> largestValues(TreeNode* root) {
        vector<int> max_arr(10001,INT_MIN);
        if(!root) return vector<int>{};

        int lvl = traverse(root,0,max_arr);
        vector<int>ans;
        for(int i=0;i<lvl;i++){
                ans.push_back(max_arr[i]);
        }
        return ans;
    }
};
