class Solution {
public: 
    unordered_map<string,vector<string>>m;
    int min_path = INT_MAX;
    bool isOneDiff(string a,string b){
        int count = 0;
        for(int i=0;i<8;i++){
            if(a[i]!=b[i]){
                count++;
            }
        }
        if(count==1){
            return true;
        }
        return false;
    }
    
    void findMinimumPath(string curr,string& target,unordered_set<string>&visited,int level){
        if(curr==target){
            min_path = min(min_path,level);
            return;
        }
        if(visited.count(curr)){
            return;
        }
        visited.insert(curr);
        for(auto& neighbor:m[curr]){
           findMinimumPath(neighbor,target,visited,level+1);
        }
        visited.erase(curr);
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {

        auto it = find(bank.begin(),bank.end(),startGene);
        if(it==bank.end()){
            bank.push_back(startGene);
        }

        for(int i=0;i<bank.size();i++){
            for(int j=i+1;j<bank.size();j++){
                if(isOneDiff(bank[i],bank[j])){
                    m[bank[i]].push_back(bank[j]);
                    m[bank[j]].push_back(bank[i]);
                }
            }
        }
        

        unordered_set<string> visited;
        // for(auto item:m){
        //     cout<<item.first<<":{";
        //     for(auto n:item.second){
        //         cout<<n<<",";
        //     }
        //     cout<<"}, "<<endl;
        // }
        findMinimumPath(startGene,endGene,visited,0);
        if(min_path==INT_MAX){
            return -1;
        }
        return min_path;
    }
};
