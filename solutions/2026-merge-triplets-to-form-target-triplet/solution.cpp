class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> filtered;
        for(auto& t:triplets){
            if(t[0]>target[0] or t[1]>target[1] or t[2]>target[2]){
                continue;
            }
            filtered.push_back(t);
        }

        vector<int> flag = {0,0,0};
        for(auto& t:filtered){
            if(t[0]==target[0]){
                flag[0]=1;
            }
            if(t[1]==target[1]){
                flag[1]=1;
            }
            if(t[2]==target[2]){
                flag[2]=1;
            }   
        }
        
        if(!flag[0] or !flag[1] or !flag[2]) return false;

        return true;
    }
};
