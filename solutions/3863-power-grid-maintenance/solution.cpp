class Solution {
public:
    void traverse(vector<vector<int>>& adjList,int curr,set<int>& myset){
        if(myset.count(curr)){
            return;
        }
        myset.insert(curr);
        for(auto& nbr: adjList[curr]){
            if(myset.count(nbr)){
                continue;
            }
            traverse(adjList,nbr,myset);
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        //create a adjList
        vector<vector<int>> adjList(c+1);
        for(auto& cn:connections){
            adjList[cn[0]].push_back(cn[1]);
            adjList[cn[1]].push_back(cn[0]);
        }

        vector<priority_queue<int,vector<int>,greater<int>>> Grids;
        int gridId = 0;
        //traverse and create connected component sets
        unordered_map<int,int>stations(c+1);
        vector<bool> visited(c+1,0);
        for(int i=1;i<=c;i++){
            //if not visited traverse
            if(visited[i]==0){
                set<int> myset;
                traverse(adjList,i,myset);

priority_queue<int,vector<int>,greater<int>> pq;
                for(auto& t: myset){
                    pq.push(t);
                }
                //for all elements in myset, add myset as stations
                    Grids.push_back(pq);
                   
                for(auto& item : myset){
                    stations[item] = gridId;
                    visited[item]=1;
                }
                    gridId++;
            }
        }
        vector<int> ans;
        unordered_map<int,int> offline;
        for(int i=1;i<=c;i++){
            offline[i]= 0;
        }
        for(auto& q: queries){
            int type = q[0];
            int st = q[1];
            if(type==1){
                //resolve by checking set
                while(!Grids[stations[st]].empty() and offline[(Grids[stations[st]].top())]){
                    Grids[stations[st]].pop();
                }
                if(Grids[stations[st]].empty()){
                    ans.push_back(-1);
                }
                else{
                    if(offline[st]==1){
                        ans.push_back(Grids[stations[st]].top());
                    }
                    else{
                        ans.push_back(st);
                    }
                }
            }
            else{
                // lazily offline the powerstation
                offline[st]=1;
            }
        }
        return ans;
    }
};
