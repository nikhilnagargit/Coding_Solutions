class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int lastIndexMetal = 0;
        int lastIndexGlass = 0;
        int lastIndexPaper = 0;
        int pickupitemstotal = 0;
        for(int i=1;i<travel.size();i++){
            travel[i]=travel[i]+travel[i-1];
        }
        for(int i=0;i<garbage.size();i++){
            pickupitemstotal += garbage[i].size();
            for(int j=0;j<garbage[i].size();j++){
                if(garbage[i][j]=='M'){
                    lastIndexMetal = i;
                }
                if(garbage[i][j]=='G'){
                    lastIndexGlass = i;
                }
                if(garbage[i][j]=='P'){
                    lastIndexPaper = i;
                }
            }
        }
        int ans = pickupitemstotal;
        if(lastIndexMetal!=0){
            ans+=travel[lastIndexMetal-1];
        }
        if(lastIndexGlass!=0){
            ans+=travel[lastIndexGlass-1];
        }
        if(lastIndexPaper!=0){
            ans+=travel[lastIndexPaper-1];
        }
        return ans;
    }
};
