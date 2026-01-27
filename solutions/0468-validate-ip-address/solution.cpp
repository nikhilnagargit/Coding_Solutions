class Solution {
public:
    bool validIPV4(string& s){
        int dots = 0 ;
        string curr = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                // check for string in range 255
                dots++;
                if(curr.size()>1 and curr[0]=='0' or curr.size()>3) return false;
                if(curr=="" or stoi(curr)>255 or stoi(curr)<0){
                    return false;
                }
                curr = "";
            }
            else if(s[i]<='9' and s[i]>='0'){
                curr += s[i];
            }
            else{
                return false;
            }
            if(dots>3) return false;
        }
        if(curr.size()>1 and curr[0]=='0') return false;
        if(curr=="" or stoi(curr)>255 or stoi(curr)<0){
                return false;
                }
        if(dots!=3) return false;
        return true;
    }

    bool validIPV6(string& s){
        int dots = 0 ;
        string curr = "";
        for(int i=0;i<s.size();i++){
            if(s[i]==':'){
                dots++;
                if(curr=="" or curr.size()>4){
                    return false;
                }
                curr = "";
            }
            else if(s[i]<='F' and s[i]>='A' or s[i]<='f' and s[i]>='a' or s[i]>='0' and s[i]<='9'){
                curr += s[i];
            }
            else{
                return false;
            }
            if(dots>7) return false;
        }
            if(curr=="" or curr.size()>4){
                    return false;
                }
        if(dots!=7) return false;
        return true;
    }

    string validIPAddress(string queryIP) {
        int s = queryIP.size();
        if(s<7 or s>40) return "Neither";
        if(validIPV4(queryIP)) return "IPv4";
        if(validIPV6(queryIP)) return "IPv6";
        return "Neither";
    }
};
