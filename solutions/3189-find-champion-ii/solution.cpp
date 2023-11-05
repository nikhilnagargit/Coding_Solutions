class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false);
        for(int i=0;i<edges.size();i++){
            int first = edges[i][0];
            int second = edges[i][1];
            
                visited[second]=true;
       
        }
        int count=0;
        int root =0;
        for( int i=0;i<n;i++){
            if(!visited[i])
            {    count++;
              root=i;
            }
        }
        
        if(count>1)
            return -1;
        return root;
    }
};
