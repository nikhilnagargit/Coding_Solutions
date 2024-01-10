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
    unordered_map<int,vector<int>> adjList;
    void fillAdjList(TreeNode* root){
        if(!root)return;
        if(root->left){
            adjList[root->val].push_back(root->left->val);
            adjList[root->left->val].push_back(root->val);
            fillAdjList(root->left);
        }
        if(root->right){
            adjList[root->val].push_back(root->right->val);
            adjList[root->right->val].push_back(root->val);
            fillAdjList(root->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        // pefrom bfs on adjList;
        fillAdjList(root);
        int time = 0;
        queue<int> q;
        unordered_set<int>visited;
        q.push(start);
        visited.insert(start);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int item = q.front();q.pop();
                for(auto neighbour: adjList[item]){
                    if(visited.find(neighbour)==visited.end()){
                        q.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
            time++;
        }
        return time-1;
    }
};
