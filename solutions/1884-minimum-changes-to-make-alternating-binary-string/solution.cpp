class Solution {
public:
    int minOperations(string s) {
        // check even
        int count0odd=0;
        int count0even=0;
        int count1odd=0;
        int count1even=0;
        for(int i=0;i<s.size();i+=2){
            if(s[i]!='0'){
                count0even++;
            }
            if(s[i]!='1'){
                count1even++;
            }
        }
        
        for(int i=1;i<s.size();i+=2){
            if(s[i]!='0'){
                count0odd++;
            }
            if(s[i]!='1'){
                count1odd++;
            }
        }

        return min(count0even+count1odd,count0odd+count1even);

    }
};
