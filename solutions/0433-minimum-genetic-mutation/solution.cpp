class Solution {
public:
// check if strings only have one char difference
    bool isOneMutation(const string& a,const string& b){
        int count=0;
        for(int i=0;i<8;i++){
            if(a[i]!=b[i])count++;
        }
        if(count==1)return true;
        return false;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // prepare the adjList using map(it will be added as bi-directional edges)
        unordered_map<string,vector<string>>m;
        for(int i=0;i<bank.size();i++){
            for(int j=i+1;j<bank.size();j++){
                if(isOneMutation(bank[i],bank[j])){
                    m[bank[i]].push_back(bank[j]);
                    m[bank[j]].push_back(bank[i]);
                }
            }
        }
        // check if endGene exist in bank or not
        int flag = false;
        for(int i=0;i<bank.size();i++){
            if(isOneMutation(bank[i],startGene)){
                m[startGene].push_back(bank[i]);
                m[bank[i]].push_back(startGene);
            }
            // check if endgene exist or not
            if(bank[i]==endGene){
                flag = true;
            }
        }
        if(!flag)return -1;

        // start traversing the graph bfs
        queue<string>q;
        unordered_set<string>vis;
        q.push(startGene);
        int count =0 ;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                string curr  = q.front();q.pop();
                vis.insert(curr);
                if(curr==endGene){
                    return count;
                }
                for(auto item:m[curr]){
                    if(vis.find(item)==vis.end()){
                        q.push(item);
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
