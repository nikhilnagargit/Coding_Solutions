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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long long> heap;
        // vector<int> v;
        // set<int> my_set;
        // v.push_back(root->val);
        // heap.push(root->val);
        while(!q.empty()){
            long long level_sum = 0;
            long long l = q.size();
            for(int i=0;i<l;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr){
                level_sum += curr->val;
                q.push(curr->left);
                q.push(curr->right);
                
                }
            }
            if(level_sum!=0){
            heap.push(level_sum);
            // cout<<"heap push->"<<level_sum<<endl;
            }
            // v.push_back(level_sum);
            // my_set.insert(level_sum);
        }

        // for(int i=0;i<k-1;i++){
        //     my_set.erase(my_set.begin());
        // }

// sort(v.begin(),v.end());
// cout<<endl;
        for(int i=0;i<k-1;i++){
            //  cout<<"heap-< "<< heap.top()<<" ,"<<heap.size()<<endl;
           if(!heap.empty()){ heap.pop();
           }
           else{
            return -1;
           }
           
        }
        // cout<<endl;
        if(heap.empty()){
            return -1;
        }
      return heap.top();
        // return *my_set.begin();
    }
};
