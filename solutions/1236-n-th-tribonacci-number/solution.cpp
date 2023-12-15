class Solution {
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 1;

        int first = 0;
        int second = 1;
        int third = 1;
        for(int i=3;i<=n;i++){
            int temp1 = third;
            int temp2 = second;
            third = first+second+third;
            first = temp2;
            second = temp1;
        }
        return third;
    }
};
