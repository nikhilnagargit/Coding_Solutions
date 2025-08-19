class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<char,int>s1;
        unordered_map<char,int>s2;
        int count1=0;
        int count2=0;
        for(int i=0;i<s.size();i++){
            if(s1.count(s[i])==0){
                s1[s[i]]=count1;
                count1++;  
            }
            s[i]= '0'+s1[s[i]];
        }
        for(int i=0;i<t.size();i++){
            if(!s2.count(t[i])){
                s2[t[i]]=count2;
                count2++;  
            }
            t[i]='0'+(s2[t[i]]);
        }
        return s==t;

    }
};
