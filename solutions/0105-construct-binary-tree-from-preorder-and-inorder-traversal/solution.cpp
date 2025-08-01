class Solution {
public:
    TreeNode* makeTree(vector<int>& preorder,vector<int>& inorder,unordered_map<int,int>& m,int left,int right,int& i){
        if(left>right){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[i]);
        int mid = m[preorder[i]];
        i++;
        root->left = makeTree(preorder,inorder,m,left,mid-1,i);
        root->right = makeTree(preorder,inorder,m,mid+1,right,i);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0;i<preorder.size();i++){
            m[inorder[i]] = i;
        }
        int i=0;
        return makeTree(preorder,inorder,m,0,preorder.size()-1,i);
    }
};
