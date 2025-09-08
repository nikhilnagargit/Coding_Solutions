class Solution {
public:
    bool zero(int a){
        if(a==0) return true;
        while(a){
            int lastdigit = a%10;
            if(lastdigit==0){
                return true;
            }
            a = a/10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a = 0;
        int b = n;
        while(zero(a) or zero(b)){
            a = a+1;
            b = b-1;
        }
        return {a,b};
    }
};
