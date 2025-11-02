class Solution {
public:




    string countAndSay(int n) {

        string s = "1";

        for(int i=1;i<n;i++){
            string news = "";
            int count = 1;
            int curr = s[0]-'0';
            int idx = 1;
            while(idx<s.size()){
                if(s[idx]!=s[idx-1]){
                    news+= to_string(count)+s[idx-1];
                    count = 1;
                }
                else{
                    count++;
                }
                idx++;
            }
            news+= to_string(count)+s[idx-1];
            s = news;
        }

        return s;
    }
};
