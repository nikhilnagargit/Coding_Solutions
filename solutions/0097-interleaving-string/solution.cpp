class Solution {
public:
    unordered_map<string,bool> m;

    bool solve(string& s1,string&s2, string& s3,int i,int j,int k){
        if(k==s3.size()){
            return true;
        }
        string s = to_string(i)+"-"+to_string(j)+"-"+to_string(k);
        if(m.find(s)!=m.end()){
            return m[s];
        }
        int nexti = i+1;
        int nextj = j+1;
        if(s1[nexti]==s3[k] and solve(s1,s2,s3,nexti,j,k+1)){ m[s]=true; return true;}
        if(s2[nextj]==s3[k] and solve(s1,s2,s3,i,nextj,k+1)){m[s]=true; return true;}
        m[s] = false;
        return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return false;
        int i=-1;
        int j=-1;
        int k=0;
        return solve(s1,s2,s3,i,j,k);
    }
};
