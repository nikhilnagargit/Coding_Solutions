class Solution {
public:

    int distinctPoints(string s, int k) {

        unordered_map<char,int>freq;
        unordered_map<char,int> totalfreq;
        for(auto&c :s){
            totalfreq[c]++;
        }
        unordered_set<string> myset;
        int left = 0;
        for(int i=0;i<k;i++){
            freq[s[i]]++;
        }
            int remU = totalfreq['U']-freq['U'];
            int remD = totalfreq['D']-freq['D'];
            int remL = totalfreq['L']-freq['L'];
            int remR = totalfreq['R']-freq['R'];
                  if(remU>=remD){
                remU = remU-remD;
                remD = 0;
            }
            else{
                remD = remD-remU;
                remU = 0;
            }
            if(remL>=remR){
                remL = remL-remR;
                remR = 0;
            }
            else{
                remR = remR-remL;
                remL = 0;
            }
        myset.insert(to_string(remU)+"-"+to_string(remD)+"-"+to_string(remL)+"-"+to_string(remR));
        for(int right = k;right<s.size();right++){
            freq[s[right]]++;
            freq[s[left]]--;
            left++;
         
            //remaining string
             remU = totalfreq['U']-freq['U'];
             remD = totalfreq['D']-freq['D'];
             remL = totalfreq['L']-freq['L'];
             remR = totalfreq['R']-freq['R'];
            if(remU>=remD){
                remU = remU-remD;
                remD = 0;
            }
            else{
                remD = remD-remU;
                remU = 0;
            }
            if(remL>=remR){
                remL = remL-remR;
                remR = 0;
            }
            else{
                remR = remR-remL;
                remL = 0;
            }
            myset.insert(to_string(remU)+"-"+to_string(remD)+"-"+to_string(remL)+"-"+to_string(remR));
        }
        
        // for(auto item:myset){
        //     cout<<item<<",";
        // }
        return myset.size();
    }
};
