class Solution {
public:
    string largestGoodInteger(string num) {
        int i=2;
        int n=num.size();
        if(n<3){
            return "";
        }
        string largest = "";
        for(int i=2;i<n;i++){
            if(num[i-2]==num[i] and num[i-1]==num[i] ){
                string s = num.substr(i-2,3);
                if(s>largest){
                    largest = s;
                }
            }
        }
        return largest;
    }
};
