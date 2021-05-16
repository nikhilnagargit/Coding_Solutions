class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0 ){
            return 0;
        }
        
       
            if(s[0]=='0'){
                return 0;
            }

        
        if(s.size()==1){
            return 1;
        }
   
        
        
        int prevprev = 1;
        int prev = 1;
        int temp;
        
        for(int i=1;i<s.size();i++){
            if(s[i]=='0' and s[i-1]=='0'){
                   return 0; 
            }
        
            else if(s[i]=='0'){
                if(s.substr(i-1,2)>"26"){
                    return 0;
                }
               prev=prevprev;
            }
            else if(s[i-1]=='0'){
                prevprev= prev;
            }
            else if( s.substr(i-1,2)>"26"){
                prev=prev;
                prevprev = prev;
            }
            else{
                temp = prev+prevprev;
                prevprev= prev;
                prev = temp;
            }
 
        }
        
        
        return prev;
    }
    
};
