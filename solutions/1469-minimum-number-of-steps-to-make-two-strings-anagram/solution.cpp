class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> map1;
        for(char c:s){
            map1[c]++;
        }
        for(char c:t){
            if(map1.find(c)!=map1.end()){
                if(map1[c]>0){
                    map1[c]--; 
                }
            }
        }
        int count =0;
        for(auto item:map1){
            count+= item.second;
        }
        return count;

    }
};
