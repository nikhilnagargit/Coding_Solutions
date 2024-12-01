class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        for(int i=0;i<n;i++){
            ans = ans*2;
            if(ans-1>=n){
                break;
            }
        }
        return ans-1;
        
    }
};
