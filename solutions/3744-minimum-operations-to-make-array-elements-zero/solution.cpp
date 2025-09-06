class Solution {
public:

    long long solveQuery(long long y){
        long long x= 1;
        long long ans = 0;
        //x and y is the range
        long long div = 1;
        while(x<=y){
            long long newx = (x*4);
            if(newx>y){
                ans+= (y-x+1)*div;
                break;
            }
            ans+= (newx-x)*div;
            x = newx;
            div++;
        }
        return ans;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto& q:queries){
            ans+= (solveQuery(q[1]) - solveQuery(q[0]-1) + 1)/2 ;
        }
        return ans;
    }
};
