class Solution {
public:
    
    int solve_first(unordered_map<int,vector<int>>&m, int distance,int startNode){
        unordered_set<int> visite;
        queue<int> q;
        q.push(startNode);
        int count = 0;
     

        while(!q.empty() and distance>-1){
            int s = q.size();
            for(int i=0;i<s;i++){
                int curr = q.front();q.pop();
                if(visite.count(curr)){
                    continue;
                }
                for(int& adj: m[curr]){
                    q.push(adj);
                }
                visite.insert(curr);
                count++;
            }
            distance--;
        }
        
        return count;
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        unordered_map<int,vector<int>> m1;
        int n1 = 0;
        for(auto edge:edges1){
            n1 = max(n1,max(edge[0],edge[1]));
            m1[edge[0]].push_back(edge[1]);
            m1[edge[1]].push_back(edge[0]);
        }
        
        int n2 = 0;
        unordered_map<int,vector<int>> m2;
        for(auto edge:edges2){
            n2 = max(n2,max(edge[0],edge[1]));
            m2[edge[0]].push_back(edge[1]);
            m2[edge[1]].push_back(edge[0]);
        }       
        
        
        vector<int>ans;
        
        //find max possible nodes for second
        int max_degree = 0;
        for(int i=0;i<=n2;i++){
            max_degree = max(max_degree,solve_first(m2,k-1,i));
        }
        
        for(int i=0;i<=n1;i++){
            //find the self connected nodes;
            int count1 = solve_first(m1,k,i);
            // int count1 = 0;
            // cout<<count1<<endl;
            ans.push_back(count1+max_degree);
        }
        return ans;
    }
};
