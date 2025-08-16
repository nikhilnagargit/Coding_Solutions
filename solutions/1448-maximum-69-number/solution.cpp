class Solution {
public:
    int maximum69Number (int num) {
        int digits = 0;
        int num_copy = num;
        int gunak = 1;
        int new_num = 0;
        while(num_copy){
            num_copy=num_copy/10;
            gunak*=10;
            digits++;
        }
        gunak = gunak/10;
        int flag = 1;

        while(gunak){
            int rem = num/gunak;
            rem = rem%10;
            if(rem==6 and flag){
                new_num += gunak*9;
                flag = 0;
            }
            else{
                new_num+= gunak*rem;
            }
            gunak=gunak/10;
        }
        return new_num;

    }
};
