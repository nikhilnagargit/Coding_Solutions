class Solution {
public:
    int minSensors(int n, int m, int k) {
        int z = 1+2*k;
        int x = 0;
        if(n%z==0){
            x=n/z;
        }
        else{
            x=n/z+1;
        }
        int y=0;
        if(m%z==0){
            y = m/z;
        }
        else{
            y = m/z+1;
        }
        return x*y;
    }
};
