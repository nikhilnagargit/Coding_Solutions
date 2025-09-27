class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> freq;
        for(auto& c:s){
            freq[c]++;
        }
        unordered_map<int,unordered_set<char>> m;
        int maxfreq = 0;
        int maxfreqnum = 0;
        for(auto item:freq){
            char c = item.first;
            int f = item.second;
            m[f].insert(c);
            if(maxfreq<m[f].size()){
                maxfreq = m[f].size();
                maxfreqnum = f;
            }
            else if(maxfreq==m[f].size() and maxfreqnum<f){
                maxfreqnum = f;
            }
        }
        string ans = "";
        for(auto i:m[maxfreqnum]){
            ans+=i;
        }
        return ans;
    }
};
