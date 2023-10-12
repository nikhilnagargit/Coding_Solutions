class Solution {
public:
    int myAtoi(string s) {
        int i=0;

        while(s[i]==' '){
            i++;
        }

        int sign = 1;
        if(s[i]=='+'){
            sign = 1;
              i++;
        }else if(s[i]=='-'){
            sign = -1;
              i++;
        }
  
    

        int value = 0 ;
        while(i<s.size()){
            if(s[i]<'0' or s[i]>'9'){
                break;
            }
            if(sign==-1){
               if(value<(INT_MIN+(s[i]-'0'))/10){
                   return INT_MIN;
               }
               else{
                   value = value*10 - (s[i]-'0') ;
               }
           }
           else if(sign==1){
            if(value>(INT_MAX-(s[i]-'0'))/10){
                   return INT_MAX;
               }
               else{
                  value = value*10 + (s[i]-'0') ;
               }
           }
            i++;
        }
   return value;
        // return value*sign;
    }
};
