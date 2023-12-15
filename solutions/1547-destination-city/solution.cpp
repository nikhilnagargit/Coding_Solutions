class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>s;
        for(auto item:paths){
            string a = item[0];
            s.insert(a);
        }
        for(auto item:paths){
            string a = item[1];
            if(s.find(a)==s.end()){
                return a;
            }
        }
        return "";
    }
};
