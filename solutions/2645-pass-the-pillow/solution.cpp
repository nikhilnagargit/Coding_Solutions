class Solution {
public:
    int passThePillow(int n, int time) {
        int step = 1;
        int curr = 1;
        while(time--){
            if(curr==1 and step==-1){
                step = 1;
            }
            if(curr==n and step==1){
                step = -1;
            }
            curr+=step;
        }
        return curr;
    }
};
