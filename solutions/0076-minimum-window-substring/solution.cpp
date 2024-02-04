class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        unordered_map<char,int> tmap ;
        unordered_map<char,int> wmap;
        int minw = INT_MAX;
        int minleft = INT_MAX;
        int minright = INT_MAX;
        for(auto c:t){
            tmap[c]++;
        }
        int count_w_ele = 0;
        int idx=0;
        while(idx<s.size()){
            if(tmap.contains(s[idx])){
                if(wmap[s[idx]]<tmap[s[idx]]){
                    wmap[s[idx]]++;
                    count_w_ele++;
                }
                else{
                    wmap[s[idx]]++;
                }
                break;
            }
            idx++;
        }
        int left = idx;
        idx = left+1;
        while(idx<s.size() and count_w_ele!=t.size()){
            if(tmap.contains(s[idx])){
                if(wmap[s[idx]]<tmap[s[idx]]){
                    wmap[s[idx]]++;
                    count_w_ele++;
                }
                else{
                    wmap[s[idx]]++;
                }
            }
            idx++;
        }
  
        int right = idx-1;
    

        minleft = left;
        minright =right;
        minw = right-left+1;
        if(right+1==s.size() and count_w_ele!=t.size()){
            return "";
        }
        while(left<s.size() and right<s.size()){
                cout<<"left:"<<left<<" right:"<<right<<endl;
            // decrease the window first
            if(wmap[s[left]]<=tmap[s[left]]){
                count_w_ele--;
            }
            wmap[s[left]]--;
            left++;
            while(left<s.size() and !tmap.contains(s[left]))
                left++;
            
            // increase the window
            
            while(right<s.size() and count_w_ele!=t.size()){
                right++;
                while(right<s.size() and !tmap.contains(s[right]))
                    right++;
                if(wmap[s[right]]+1 == tmap[s[right]]){
                    count_w_ele++;
                }
                wmap[s[right]]++;               
            } 
            if(count_w_ele==t.size() and minw>(right-left+1)){
                minw = right-left+1;
                minright = right;
                minleft = left;
            }
        }
        cout<<count_w_ele;
        return s.substr(minleft,minright-minleft+1);
    }
};
