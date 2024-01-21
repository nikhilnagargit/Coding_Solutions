class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>m;
        for(auto c:word){
            m[c]++;
        }
        vector<int>v;
        for(auto item:m){
            v.push_back(item.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        int ans = 0;
        if(v.size()<=8){
            for(int i=0;i<v.size();i++){
                ans+= v[i];
            }
        }
        else if(v.size()<=16 ){
            for(int i=0;i<8;i++){
                ans+= v[i];
            }
            for(int i=8;i<v.size();i++){
                ans+= 2*v[i];
            }
        }
        else if(v.size()<=24){
            for(int i=0;i<8;i++){
                ans+= v[i];
            }
            for(int i=8;i<16;i++){
                ans+= 2*v[i];
            }
            for(int i=16;i<v.size();i++){
                ans+= 3*v[i];
            }
        }
        else if(v.size()<=26){
            for(int i=0;i<8;i++){
                ans+= v[i];
            }
            for(int i=8;i<16;i++){
                ans+= 2*v[i];
            }
            for(int i=16;i<24;i++){
                ans+= 3*v[i];
            }
            for(int i=24;i<v.size();i++){
                ans+= 4*v[i];
            }
        }
        return ans;
    }
};
