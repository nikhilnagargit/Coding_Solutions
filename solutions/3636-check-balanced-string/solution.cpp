class Solution {
public:
    bool isBalanced(string num) {
        int esum = 0, osum = 0;
        for(int i=0;i<num.size();i++){
            if(i%2==0){
                osum+= (num[i]-'0');
            }
            else{
                esum+= (num[i]-'0');
            }
        }
        return esum==osum;
    }
};
