class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
       sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        
        int max_h = 1;
        int counter =1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i-1]+1==hBars[i]){
                counter++;
            }
            else{
                counter = 1;
            }
            max_h = max(max_h,counter);
        }
        max_h = max_h+1;
        int max_v = 1;
        counter =1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i-1]+1==vBars[i]){
                counter++;
            }
            else{
                counter = 1;
            }
            max_v = max(max_v,counter);
        }        
        max_v = max_v+1;
        
        int side = min(max_h,max_v);
        return side*side;
    }
};
