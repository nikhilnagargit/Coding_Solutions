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
    void Resolve(string s,int parentDepth,TreeNode* parentRoot){
        if(s==""){
            return;
        }

        int N = s.size();
        int i=0;
        int num = 0;
        int D = 0;
        vector<pair<int,int>> indexesFound;
        while(i<N){
            while(i<N and s[i]=='-'){
                D++;
                i++;
            }
            while(i<N and s[i]!='-'){
                num = num*10 + (s[i]-'0');
                i++;
            }
            if(D==parentDepth+1){
                indexesFound.push_back({i,num});
            }
            D = 0;
            num = 0;
        }
        if(indexesFound.size()==1){

            string newS = s.substr(indexesFound[0].first);
            parentRoot->left = new TreeNode(indexesFound[0].second);
            parentRoot->right = nullptr;
            Resolve(newS,parentDepth+1,parentRoot->left);
        }
        else{
            int secondNumLength = 0;
            int secondNum = indexesFound[1].second;
            while(secondNum){
                secondNum = secondNum/10;
                secondNumLength++;
            }
            string newS1 = s.substr(indexesFound[0].first,indexesFound[1].first-indexesFound[0].first-secondNumLength-(parentDepth+1));
            parentRoot->left = new TreeNode(indexesFound[0].second);
            Resolve(newS1,parentDepth+1,parentRoot->left);

            string newS2 = s.substr(indexesFound[1].first);
            parentRoot->right = new TreeNode(indexesFound[1].second);
            Resolve(newS2,parentDepth+1,parentRoot->right);
        }
    }

    TreeNode* recoverFromPreorder(string traversal) {

        TreeNode* root = new  TreeNode();
        int i = 0;
        int N = traversal.size();
        int num = 0;
        while(i<N and traversal[i]!='-'){
            num = num*10 + (traversal[i]-'0');
            i++;
        }
        string newS = traversal.substr(i);
        root->val = num;
        Resolve(newS,0,root);
        return root;
    }

};



