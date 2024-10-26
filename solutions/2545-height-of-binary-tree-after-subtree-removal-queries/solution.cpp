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
        int maxHeightAfterRemoval[100001];
        int currentMaxHeight = 0;

    void traverseLeftToRight(TreeNode* node,int currHeight){
        if(!node){
            return;
        }
        maxHeightAfterRemoval[node->val]= currentMaxHeight;
        currentMaxHeight = max(currentMaxHeight,currHeight);
        traverseLeftToRight(node->left,currHeight+1);
        traverseLeftToRight(node->right,currHeight+1);
    }
    void traverseRightToLeft(TreeNode* node,int currHeight){
        if(!node){
            return;
        }
        maxHeightAfterRemoval[node->val]= max(currentMaxHeight,maxHeightAfterRemoval[node->val]);

        currentMaxHeight = max(currentMaxHeight,currHeight);
        traverseRightToLeft(node->right,currHeight+1);
        traverseRightToLeft(node->left,currHeight+1);
    }
   

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

traverseLeftToRight(root,0);
currentMaxHeight = 0;
traverseRightToLeft(root,0);

vector<int>result ;
for(auto q:queries){
    result.push_back(maxHeightAfterRemoval[q]);
}
return result;
}
    
};
