class Solution {
public:
    string lastNonEmptyString(string s) {
           int maxcount = 0;
        unordered_map<char,pair<int,int>> m;
        for(int i=0;i<s.size();i++){
            m[s[i]].first+=1;
            m[s[i]].second = i;
             maxcount = max(maxcount,m[s[i]].first);
        }
    
        
        // cout<<maxcount<<endl;
        vector<pair<int,char>>v;
        
        for(auto item:m){
            // cout<<"-"<<item.second.first<<"-"<<endl;
            if(item.second.first==maxcount){
                v.push_back({item.second.second,item.first});
            // cout<<"{"<<item.second.second<<","<<item.first<<"},";
            }
        }
        // cout<<endl;
        sort(v.begin(),v.end());
        string ans = "";
        for(auto i:v){
            ans+= i.second;
        }
        return ans;
    }
};
