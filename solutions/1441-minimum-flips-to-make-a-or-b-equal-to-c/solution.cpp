class Solution {
public:
    int minFlips(int a, int b, int c) {
        int aorb = a|b;
        int ans =0;
        for(int i=0;i<32;i++){
            int first = 0;
            int second = 0;
            if((aorb & (1<<i))!=0){
                first = 1;
            }
            if((c & (1<<i))!=0){
                second = 1;
            }
            if(first!=second){
                if(first==1 and second==0){
                    if(a & (1<<i)){
                        ans += 1;
                    }
                    if(b & (1<<i)){
                        ans += 1;
                    }
                }
                else{
                    ans+=1;
                }
            }
        }
     return ans;   
    }
};
