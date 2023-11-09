class Solution {
public:
    bool isHappy(int n) {
        int repeat = 1000;
        int num = n;
        int sum;
        while(repeat--){
            sum = 0;
            while(num){
                sum+= pow(num%10,2);
                num = num/10;
            }
            num = sum;
            if(num==1){
                return true;
            }
        }

        return false;
    }
};
