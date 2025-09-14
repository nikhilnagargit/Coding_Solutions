class Solution {
public:
    string lowercase(string& s){
        string ans = "";
        for(auto& c:s){
            ans+= tolower(c);
        }
        return ans;
    }
    string pattern(string& s){
        string ans = "";
        for(auto& c:s){
            char cl = tolower(c);
            if(cl=='a' or cl=='e' or cl=='i' or cl=='o' or cl=='u'){
                ans+='*';
            }
            else{
                ans+= cl;
            }
        }
        return ans;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string,int> exactmatch;
        unordered_map<string,int> ordermatch;
        unordered_map<string,int> vowelmatch;
        for(int i=0;i<wordlist.size();i++){
            if(!exactmatch.count(wordlist[i])){
                exactmatch[wordlist[i]] = i;
            }
            string l = lowercase(wordlist[i]);
            if(!ordermatch.count(l)){
                ordermatch[l] = i;
            }
            string p = pattern(wordlist[i]);
            if(!vowelmatch.count(p)){
                vowelmatch[p] = i;
            }
        }

        vector<string> ans;
        for(auto& q:queries){
            if(exactmatch.count(q)){
                ans.push_back(wordlist[exactmatch[q]]);
                continue;
            }
            string l = lowercase(q);
            if(ordermatch.count(l)){
                 ans.push_back(wordlist[ordermatch[l]]);
                 continue;
            }
            string p = pattern(q);
            if(vowelmatch.count(p)){
                 ans.push_back(wordlist[vowelmatch[p]]);
                 continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};
