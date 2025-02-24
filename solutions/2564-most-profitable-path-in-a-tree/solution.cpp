class Solution {
public:
    int maxProfit = INT_MIN;
    unordered_map<int,vector<int>> adjList;

    bool findBobsPath(vector<bool>&visited,vector<int>&bobsPath){
        if(bobsPath[bobsPath.size()-1]==0){
            return true;
        }
        int curr = bobsPath[bobsPath.size()-1];
        visited[curr] = 1;
        for(int& neighbour : adjList[curr]){
            if(!visited[neighbour]){
                bobsPath.push_back(neighbour);
                if(findBobsPath(visited,bobsPath)){return true;}
                bobsPath.pop_back();
            }
        }
        return false;
    }

    void traverseAlicesPath(vector<bool>& gates,vector<int>& amount,int currAliceProfit,int currTime,int currNode,vector<int>&bobsPath,vector<bool>& visited){

        // check if curr gate is open or not for alice
        int bobsCurrNode = -1;
        if(currTime<bobsPath.size()){
           bobsCurrNode = bobsPath[currTime];
        }

        if(gates[currNode]){
            // gate open, it means no reward
        }
        else{
            //not open, check if they are on same node
            if(bobsCurrNode!=-1 and bobsCurrNode==currNode){
                currAliceProfit += amount[currNode]/2;
            }
            else{
                currAliceProfit += amount[currNode];
            }
        }
        // cout<<currAliceProfit<<",";

        //mark the curr gate open
        // gates[currNode] =1 ;
        if(bobsCurrNode!=-1)
        gates[bobsCurrNode] = 1;
        visited[currNode] = 1;
        //move forward
        int flat = 0;
        for(auto& neighbour:adjList[currNode]){
            if(!visited[neighbour]){
                flat = 1;
                traverseAlicesPath(gates,amount,currAliceProfit,currTime+1,neighbour,bobsPath,visited);
            }
        }
        if(bobsCurrNode!=-1)
        gates[bobsCurrNode] = 0;
        if(flat==0){
             maxProfit = max(maxProfit,currAliceProfit);
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int currAliceProfit = 0 ;
        vector<bool> gates(amount.size(),0);
        vector<bool>visited(amount.size(),0);
        for(auto& e:edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<int> bobsPath;
        bobsPath.push_back(bob);
        findBobsPath(visited,bobsPath);
        visited = vector<bool>(amount.size(),0);
        traverseAlicesPath(gates,amount,currAliceProfit,0,0,bobsPath,visited);
        return maxProfit;
    }
};
