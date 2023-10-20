class Solution {
public:


    string addBinary(string a, string b) {
        string ans = "";
        char carry='0';
        int i = a.size()-1;
        int j = b.size()-1;
        char first = '0';
        char second = '0';
        while(i>=0 or j>=0){

            if(i<0 and j>=0){
                first = '0';
                second= b[j]; 
                j--;
            }
            else if(j<0 and i>=0){
                first = a[i];
                second = '0';
                i--;
            }
            else if(i>=0 and j>=0){
                first = a[i];
                second = b[j];
                i--;
                j--;
            }

            if(((first=='0' and second=='1') or (first=='1' and second=='0')) and carry=='0'){
                carry = '0';
                ans='1'+ans;
            }
            else if(((first=='0' and second=='1') or (first=='1' and second=='0')) and carry=='1'){
                carry = '1';
                ans='0'+ans;
            }
            else if(first=='0' and second=='0' and carry =='0'){
                carry = '0';
                ans='0'+ans;
            }
            else if(first=='1' and second=='1' and carry =='0'){
                carry = '1';
                ans='0'+ans;
            }
            else if(first=='0' and second=='0' and carry =='1'){
                carry = '0';
                ans='1'+ans;
            }
            else {
                carry = '1';
                ans='1'+ans;
            }
        }

        if(carry=='1'){
            ans='1'+ans;
        }
        return ans;
    }
};
