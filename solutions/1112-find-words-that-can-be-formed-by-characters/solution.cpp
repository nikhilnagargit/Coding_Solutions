class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>m;
        for(auto c:chars){
            m[c]++;
        }
        int ans=0;

        unordered_map<char,int>temp_m;
        temp_m= m;

        for(auto s:words){
            int flag = false;
            for(int i=0;i<s.size();i++){
                if(temp_m.find(s[i])==temp_m.end()){
                    temp_m = m;
                    break;
                }
                else if(temp_m[s[i]]==0){
                    temp_m = m;
                    break;
                }
                else{
                    temp_m[s[i]]--;
                }
                if(i==s.size()-1){
                    flag = true;
                }
            }
            temp_m = m;
            if(flag)
            ans+= s.size();
        }
        return ans;

    }
};
