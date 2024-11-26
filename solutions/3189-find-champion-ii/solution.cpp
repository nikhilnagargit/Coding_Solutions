class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        if(edges.size()==0){
            if(n<=1) return 0;
            return -1;
        }
        
        vector<int> starters;
        unordered_set<int> aane_wale;
        unordered_set<int> jaane_wale;
        for(auto edge:edges){
            jaane_wale.insert(edge[0]);
            aane_wale.insert(edge[1]);
        }
        for(auto i:jaane_wale){
            if(aane_wale.count(i)==0){
                starters.push_back(i);
            }
        }
        jaane_wale.insert(aane_wale.begin(),aane_wale.end());
        if(jaane_wale.size()!=n){
            return -1;
        }
        if(starters.size()!=1){
            return -1;
        }
        return starters[0];
    }
};
