 
unordered_map<char,int> m;
static bool custom_compare(char& a,char& b){
        if(m[a]>=m[b])return false;
        return true;
}

class Solution {  
public:
    string customSortString(string order, string s) {
        int count = 0;
        for(char& i:order){
            m[i] = count++;
        }
        string part1="";
        string part2="";
        for(char& i:s){
            if(m.find(i)==m.end()){
                part2+= i;
            }
            else{
                part1+= i;
            }
        }
        sort(part1.begin(),part1.end(),custom_compare);
        return part1+part2;
    }
};
