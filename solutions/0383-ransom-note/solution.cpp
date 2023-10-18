class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>m;
        for( int i=0;i<magazine.size();i++){
            if(m.find(magazine[i])==m.end()){
                m[magazine[i]] = 1;
            }
            else{
                m[magazine[i]]+=1;
            }
        }


        for(int i=0;i<ransomNote.size();i++){
            if(m.find(ransomNote[i])==m.end()){
                return false;
            }
            else if(m[ransomNote[i]]==0){
                return false;
            }
            else{
                m[ransomNote[i]] -=1;
            }
        }
        return true;
    }
};
