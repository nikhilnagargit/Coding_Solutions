class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0;
        int flag = 0;
        for(int i=31;i>=0;i--){
            if(flag){
                ans = ans|(1<<i);
            }
            else{
                if(((n)&(1<<i))){
                    flag = 1;
                    ans = ans|(1<<i);
                }
            }
        }
        return ans;
    }
};
