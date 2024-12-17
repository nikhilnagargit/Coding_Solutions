class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char,int> m;
        for(auto& c:s){
            m[c]++;
        }
        char go_back = '-';
        string ans ="";
        
        while(m.size()!=0){
            if(go_back!='-'){
                if(m.size()<=1){
                    break;
                }
                auto curr =*prev(m.end(),2);
                    m[curr.first]--;
                        ans+= curr.first;
                        if(m[curr.first]==0){
                            m.erase(curr.first);
                        }
                    go_back = '-';
               
            }
            else{
                if(m.size()==0){
                    break;
                }
                auto curr = *prev(m.end());
            
                if(m[curr.first]<=repeatLimit){
                   
                    while(m[curr.first]--){
                        ans+= curr.first;
                    }
                    m.erase(curr.first);
                    go_back = '-';
                }
                else{
                    m[curr.first] = m[curr.first] - repeatLimit;
                    int temp = repeatLimit;
                    while(temp--){
                        ans+= curr.first;
                    }
                    go_back = curr.first;
                }
            }
        }

        return ans;
    }
};
