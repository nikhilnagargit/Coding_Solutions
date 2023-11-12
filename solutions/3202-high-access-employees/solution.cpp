class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        unordered_map<string,vector<int>>mymap;
        for(auto item:access_times){
            mymap[item[0]].push_back(stoi(item[1]));
        }
        for(auto m:mymap){
            sort(begin(m.second),end(m.second));
            if(m.second.size()<=2){
                continue;
            }
            int i=0;
            while(i+2<m.second.size()){
                if(m.second[i+2]-m.second[i]<100){
                    ans.push_back(m.first);
                    break;
                }
                i++;
            }
        }
        return ans;
    }
};
