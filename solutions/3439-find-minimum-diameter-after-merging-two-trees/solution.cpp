class Solution {
public:
    pair<int,int> find_longest(unordered_map<int,vector<int>>& m,int start){
        queue<int> q;
        unordered_set<int> visited;
        int last_node = start;
        q.push(start);
        int len = 0;
        while(!q.empty()){
            int s = q.size();
            bool flag = false;
            for(int i=0;i<s;i++){
                int curr = q.front();q.pop();
                visited.insert(curr);
                for(auto neighbour:m[curr]){
                    if(visited.count(neighbour)==0){
                        q.push(neighbour);
                        last_node = neighbour;
                        flag = true;
                    }
                }
            }
            if(flag)
            len++;
        }
        return {last_node,len};
    }

    int find_minimum_path(unordered_map<int,vector<int>>& m){
        auto p1 = find_longest(m, 0);

        // Second BFS from the farthest node to determine the diameter
        auto p2 = find_longest(m, p1.first);

        return p2.second;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>> m1;
        unordered_map<int,vector<int>> m2;
        for(auto& edge:edges1){
            m1[edge[0]].push_back(edge[1]);
            m1[edge[1]].push_back(edge[0]);
        }
        for(auto& edge:edges2){
            m2[edge[0]].push_back(edge[1]);
            m2[edge[1]].push_back(edge[0]);
        }
        int p1 = find_minimum_path(m1);
        // cout<<p1.second<<endl;
 
        int p2 = find_minimum_path(m2);
 
        // cout<<p2.second;
        int a1 = (p1%2==0)?(p1/2):(p1/2+1);
        int a2 = (p2%2==0)?(p2/2):(p2/2+1);
        // cout<<a1<<endl<<a2;
        return max(a1+a2+1,max(p1,p2));
        // return max(p1.first+p2.first+1,max(p1.second,p2.second));
    }
};
