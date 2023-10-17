class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // find the root node
        unordered_set<int> children;
        int root=-1;
        children.insert(leftChild.begin(),leftChild.end());
        children.insert(rightChild.begin(),rightChild.end());
        for(int i=0;i<n;i++){
            if(children.find(i)==children.end()){
                root = i;
                break;
            }
        }
        if(root==-1){
            return false;
        }
  
        // try with dfs traversal and check if any element comes twice
        unordered_set<int> seen;
        stack<int> dfs_stack;
        dfs_stack.push(root);
        seen.insert(root);
        // start traversal
        int current;
        while(!dfs_stack.empty()){
            current = dfs_stack.top();
            dfs_stack.pop();

              int left = leftChild[current];
                int right = rightChild[current];
        if(left!=-1){
        if(seen.find(left)!=seen.end()){
                return false;
            }
                dfs_stack.push(left);
                  seen.insert(left);
            }

  if(right!=-1){
        if(seen.find(right)!=seen.end()){
                return false;
            }
                dfs_stack.push(right);
                  seen.insert(right);
            }

       
    }
     return seen.size()==n;
    }
};

