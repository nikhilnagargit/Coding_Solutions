class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int counter =0;
        map<char,int> m;
        string code1="";
        string code2="";

        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
                m[s[i]] = counter;
                code1+=to_string(counter)+".";
                counter++;
            }
            else{
                code1+=to_string(m[s[i]])+".";
            }
        }

        m.clear();

        counter =0;
                for(int i=0;i<t.size();i++){
            if(m.find(t[i])==m.end()){
                m[t[i]] = counter;
                code2+=to_string(counter)+".";
                counter++;
            }
            else{
                code2+=to_string(m[t[i]])+".";
            }
        }

        cout<<code1<<" "<<code2;
        if(code1==code2){
            return true;
        }
        return false;
    }
};
