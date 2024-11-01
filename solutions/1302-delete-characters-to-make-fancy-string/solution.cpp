class Solution {
public:
    string makeFancyString(string s) {
        vector<pair<char,int>> arr;
        int count = 1;
        char prev = '-';
        for(char c:s){
            if(prev!=c){
                arr.push_back({prev,count});
                count= 1;
                prev = c;
            }
            else{
                count++;
            }
        }
        arr.push_back({prev,count});
        
        string ans = "";
        vector<pair<char,int>> brr(arr.begin()+1,arr.end());
        for(auto p:brr){
            if(p.second>=2){
                ans+= p.first;
                ans+= p.first;
            }
            else {
                ans+= p.first;
            }
        }

        return ans;
    }
};
