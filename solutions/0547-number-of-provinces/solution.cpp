class Solution {
public:
    int findCircleNum(vector<vector<int>>& matrix) {
        unordered_map<int,vector<int>>adjList;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    adjList[i].push_back(j);
                }
            }
        }
        vector<bool>visited(m,false);
        queue<int> q;
        q.push(0);
        int count = 0;

        while(true){
            count++;
            while(!q.empty()){
                int curr = q.front();q.pop();
                if(visited[curr]==false){
                    visited[curr] = true;
                    for(int i=0;i<adjList[curr].size();i++){
                        q.push(adjList[curr][i]);
                    }   
                }
            }
            for(int i=0;i<m;i++){
                if(visited[i]==false){
                    q.push(i);
                    break;
                }
                if(i==m-1){
                    return count;
                }
            }
            
        }
        return count;

    }
};
