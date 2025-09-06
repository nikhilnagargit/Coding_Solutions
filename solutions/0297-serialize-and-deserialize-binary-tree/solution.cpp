/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public: 

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string st = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* curr = q.front();q.pop();
                if(!curr){
                    st+=" ,";
                    continue;
                }
                else{
                st+= to_string(curr->val)+",";
                }
                if(curr->left){
                    q.push(curr->left);
                }
                else{
                    q.push(nullptr);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                else{
                    q.push(nullptr);
                }
            }
        }
        return st;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        string token = "";
        deque<TreeNode*> dq;

        for(int i=0;i<s.size();i++){
            if(s[i]==','){
                if(token==" "){
                    dq.push_back(nullptr);
                }
                else{
                    TreeNode* temp = new TreeNode(stoi(token));
                    dq.push_back(temp);
                }
                token="";
            }
            else{
                token+= s[i];
            }
        }

        TreeNode* root = dq.front();
        dq.pop_front();

        queue<TreeNode*> q;
        q.push(root);

        while(!dq.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* curr = q.front();q.pop();
                curr->left = dq.front();
                dq.pop_front();
                curr->right = dq.front();
                dq.pop_front();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
