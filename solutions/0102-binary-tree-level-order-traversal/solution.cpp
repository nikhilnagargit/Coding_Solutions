class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int count = 0;
        level(root , count , result);
        return result;

    }
private:
    void level(TreeNode* root , int count , vector<vector<int>> &result){
        if(root == NULL){
            return ;
        }

        if(result.size() <= count){
            result.push_back(vector<int>());
        }
        result[count].push_back(root->val);
        count++;
        level(root->left , count , result);
        level(root->right , count , result);
  
    }    
};
