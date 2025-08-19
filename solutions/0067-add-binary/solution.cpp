class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";

        char carry = '0';
        for(int i=0;i<max(a.size(),b.size());i++){
            char first = '0';
            char second = '0';
            if(i<a.size()){
                first = a[a.size()-i-1];
            }
            if(i<b.size()){
                second = b[b.size()-i-1];
            }

            char result = '0';

            if(first=='1' and second=='1'){
                if(carry=='1'){
                    result = '1';
                    carry = '1';
                }
                else{
                    result = '0';
                    carry = '1';
                }
            }
            else if((first=='0' and second=='1') or (first=='1' and second =='0')){
                if(carry=='1'){
                    result = '0';
                    carry = '1';
                }
                else{
                    result ='1';
                    carry = '0';
                }
            }
            else{
                if(carry=='1'){
                    result = '1';
                    carry = '0';
                }
                else{
                    result = '0';
                    carry = '0';
                }
            }

            ans = result+ans;

        }
        if(carry=='1'){
            ans = carry + ans;
        }
        return ans;
    }
};
