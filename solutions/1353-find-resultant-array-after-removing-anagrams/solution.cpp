class Solution {
public:
    bool isAnagram(string& a, string& b){
        if(a.size()!=b.size()) return false;
        vector<int> freqa(26,0);
        vector<int> freqb(26,0);
        for(int i=0;i<a.size();i++){
            freqa[a[i]-'a']++;
            freqb[b[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freqa[i]!=freqb[i]) return false;
        }
        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string parent = words[0];
        for(int i=0;i<words.size();i++){
            if(isAnagram(parent,words[i])){

            }
            else{
                ans.push_back(parent);
                parent = words[i];
            }
        }
        ans.push_back(parent);
        return ans;
    }
};
