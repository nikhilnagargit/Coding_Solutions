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
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> v;
            for(int i=0;i<s;i++){
                TreeNode* curr = q.front();q.pop();
                if(curr==nullptr) continue;
                if(curr->left!=nullptr) {q.push(curr->left);v.push_back(curr->left->val);}
                if(curr->right!=nullptr) {q.push(curr->right);v.push_back(curr->right->val);}
            }
            //do the selection sort
            for(int i=0;i<v.size();i++){
                int min_index = i;
                int min_number = v[min_index];
                for(int j=i+1;j<v.size();j++){
                    if(min_number>v[j]){
                        min_number = v[j];
                        min_index = j;
                    }
                }
                if(i!=min_index){
                    int temp = v[i];
                    v[i] = v[min_index];
                    v[min_index] = temp;
                    ans++;
                }
            }            
             v.clear();
        }
        return ans;
    }
};
