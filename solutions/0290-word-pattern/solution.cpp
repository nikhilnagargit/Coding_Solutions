class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> v;
        string temp = "";
        for(auto c: s){
            if(c==' '){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp+= c;
            }
        }
        if(temp!="")
        v.push_back(temp);

        if(v.size()!=p.size()) return false;
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;

        for(int i=0;i<p.size();i++){
            if(m1.count(p[i]) and m2.count(v[i])){
                if(m1[p[i]]==v[i] and m2[v[i]]==p[i]){
                    // cout<<"1";
                }
                else{
                    //  cout<<"2";
                    return false;
                }
            }
            else if(!m1.count(p[i]) and !m2.count(v[i])){
                m1[p[i]]=v[i];
                m2[v[i]]=p[i];
            }
            else{
                //  cout<<"3";
                return false;
            }
        }
        return true;
    }
};
