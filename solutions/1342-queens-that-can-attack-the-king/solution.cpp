class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        // traverse all eight directions
        vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        vector<vector<int>> Q(8,vector<int>(8,0));
        for(auto q:queens){
            Q[q[0]][q[1]]=1;
        }
        for(auto & d: directions){
            // start from king, stop going in that direction if enocunter a queen
            int i=king[0];
            int j=king[1];
            while(i>=0 and i<8 and j>=0 and j<8){
                i+= d.first;
                j+= d.second;
                if(i>=0 and i<8 and j>=0 and j<8){
                    if(Q[i][j]){
                        ans.push_back({i,j});
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
