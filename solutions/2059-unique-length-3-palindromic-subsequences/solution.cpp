class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> myset;
        vector<int> rightFreq(26,0);
        vector<int> leftFreq(26,0);
        for(auto& c: s){
            rightFreq[c-'a']++;
        }
        for(auto& c:s){
            rightFreq[c-'a']--;
            //operations
            for(int i=0;i<26;i++){
                    if(rightFreq[i]>0 and leftFreq[i]>0){
                        string temp = "";
                        temp+= c;
                        temp = temp + (char)('a'+i);
                        temp = (char)('a'+i)+temp;
                        myset.insert(temp);
                    }
            }
            //increase in left
            leftFreq[c-'a']++;
        }
        return myset.size();
    }
};
