class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;

        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        
        for(auto& c:s1){
            m1[c]++;
        }

        for(int i=0;i<s1.size();i++){
            m2[s2[i]]++;
        }

        //sliding window
        if(m1==m2){
            return true;
        }   

        for(int i=s1.size();i<s2.size();i++){
            m2[s2[i]]++;
            m2[s2[i-s1.size()]]--;
            if(m2[s2[i-s1.size()]]==0){
                m2.erase(s2[i-s1.size()]);
            }
    //             for (const auto& pair : m1) {
    //     std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    // }
    // cout<<"-----------"<<endl;
    //     for (const auto& pair : m2) {
    //     std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    // }
            if(m1==m2){
                return true;
            }         
        }
        return false;
    }

};
