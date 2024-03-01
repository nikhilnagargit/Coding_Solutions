class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count_ones = 0;
        int count_zeros = 0;
        for(auto c:s){
            if(c=='0') count_zeros++;
            else count_ones++;
        }
        string ans = "";
        for(int i=0;i<count_ones-1;i++){
            ans+='1';
        }
        for(int i=0;i<count_zeros;i++){
            ans+='0';
        }
        ans+='1';
        return ans;
    }
};
