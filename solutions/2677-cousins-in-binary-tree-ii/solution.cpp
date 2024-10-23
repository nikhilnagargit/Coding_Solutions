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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> level_sums;
        queue<TreeNode*> q;
        q.push(root);
        level_sums.push_back(root->val);
        while(!q.empty()){
            int level_sum = 0;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left){
                    level_sum+= curr->left->val;
                    q.push(curr->left);
                }
                if(curr->right){
                    level_sum+= curr->right->val;
                    q.push(curr->right);
                }
            }
            level_sums.push_back(level_sum);
        }


        q.push(root);
        int level = 1;
        root->val = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(level==0){
                    if(curr->left){
                        curr->left->val = 0;
                    }
                    if(curr->right){
                        curr->right->val = 0;
                    }

                }
                else{
                int sibling_sum = (curr->left?curr->left->val:0)+(curr->right?curr->right->val:0);
                   int newValue = level_sums[level]-sibling_sum;
                if(curr->left){
                    q.push(curr->left);
                    curr->left->val = newValue;
                }
            
                if(curr->right){

                    q.push(curr->right);
                    curr->right->val = newValue;
                }
                }

             



            }
            level++;
        }

        return root;
        
    }
};
