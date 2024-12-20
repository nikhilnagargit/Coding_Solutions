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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> v;
        v.push_back(root);
        int level = 0;
        while(v.size()!=0){
            // cout<<level<<endl;
            vector<TreeNode*> newv;
            for(auto p:v){
                if(p->left!=nullptr)
                newv.push_back(p->left);
                if(p->right!=nullptr)
                newv.push_back(p->right);
            }
            // cout<<newv.size()<<endl;
            if(level%2==0){
                int left = 0;
                int right = newv.size()-1;
                while(left<right){
                    int temp = newv[left]->val;
                    newv[left]->val = newv[right]->val;
                    newv[right]->val = temp;
                    left++;
                    right--;
                }
            }
            v.clear();
            v = newv;
            level++;
        }
        return root;
    }
};
