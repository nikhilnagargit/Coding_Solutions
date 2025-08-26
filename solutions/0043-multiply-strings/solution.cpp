
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> result (num1.size()+num2.size(),0);
        
        for(int i=num1.size()-1;i>=0;i--){
            int carry = 0;
            for(int j=num2.size()-1;j>=0;j--){
                int mul = (num1[i]-'0') * (num2[j]-'0');
                result[i+j+1] += mul ;
                result[i+j] += result[i+j+1]/10;
                result[i+j+1] = result[i+j+1]%10;
            }
        }
        string ans = "";
        int i=0;
        
        while(i<result.size() and result[i]==0){
            i++;
        }
        if(i==result.size()) return "0";
        for(int k=i;k<result.size();k++){
            ans+= to_string(result[k]);
        }
        return ans;
    }
};

