class Solution {
public:
    vector<string> ans;
    // check if a formed item is valid
    bool isValidItem(string item){
        // no prefix zero
        if(item=="")return false;
        if(item.size()>1 and item[0]=='0')return false;
        if(stoi(item)>255)return false;
        return true;
    }
    void solve(string& s, int i, int remainingDots ,vector<string>& v){
        // base cases
        if(i==s.size()){
            return;
        }
        if(remainingDots<0){
            return;
        }
        if(remainingDots==0 and i<s.size()){
            string item = s.substr(i);
            if(isValidItem(item)){
                v.push_back(item);
                // form the ip address and push in answer
                string temp = "";
                for(int j=0;j<v.size();j++){
                    if(j!=v.size()-1)
                    temp+= v[j] + ".";
                    else
                    temp+= v[j];
                }
                ans.push_back(temp);
                v.pop_back();
                return;
            }
        }
        for(int l=1;l<=3;l++){
            if(i+l>=s.size()){
                continue;
            }
            string item = s.substr(i,l);
            if(isValidItem(item)){
                v.push_back(item);
                solve(s,i+l,remainingDots-1,v);
                v.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4 or s.size()>12)return ans;
        int remainingDots = 3;
        vector<string> v;
        solve(s,0,remainingDots,v);
        return ans;
    }
};
