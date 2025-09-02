class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,int> parentmap;
        for(auto e:edges){
            parentmap[e[0]] = e[0];
            parentmap[e[1]] = e[1];
        }

        for(auto e:edges){
            int a = e[0];
            int b = e[1];
            //find the parent of a and b, if they are same, no union will be performed
            while(parentmap[a]!=a){
                a = parentmap[a];
            }
            while(parentmap[b]!=b){
                b = parentmap[b];
            }
            if(a==b){
                return e;
            }
            //perform union
            parentmap[a] = b;
        }
       return {0,0};
    }
};
