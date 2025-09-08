class Solution {
public:
    int getSum(int num1, int num2) {
        int carry = 0;
        int ans = 0;
        for(int i=0;i<32;i++){
            int mask = 1<<i;
            int a = mask&num1;
            int b = mask&num2;
            int c = mask&(carry);
            int count = 0;
            if(a) count++;
            if(b) count++;
            if(c) count++;
            if(count==1){
                ans = ans|mask;
                carry=0;
            }
            else if(count==2){
                carry = mask<<1;
            }
            else if(count==3){
                ans = ans|mask;
                carry = mask<<1;
            }
        }
        if(carry){
            ans = ans|carry;
        }

        return ans;
    }
};
