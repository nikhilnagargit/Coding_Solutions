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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            bool isEvenRow = (level%2==0);
            int prev = -1;
            if(isEvenRow) prev = -1;
            else prev = INT_MAX;
            // cout<<endl;
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();q.pop();
                int item = curr->val;
                // cout<<item<<",";
                // check for even row
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                if(isEvenRow and (prev>=item or item%2==0)){
                    return false;
                }
                // check for odd row
                else if(!isEvenRow and (prev<=item or item%2!=0)){
                    return false;
                }
                // update previous
                prev = item;
            }
            level++;
        }
        return true;
    }
};
