class Solution {
public:
    int romanToInt(string s) {
unordered_map<char, int> m = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};;
        int num = m[s[s.size()-1]];
        
        for(int i=s.size()-2;i>=0;i--){
            int multiplier = 1;
            if((s[i]=='I' and (s[i+1]=='V' or s[i+1]=='X'))
            or (s[i]=='X' and (s[i+1]=='L' or s[i+1]=='C'))
            or (s[i]=='C' and (s[i+1]=='D' or s[i+1]=='M'))){
                multiplier = -1;
            }
            num+= m[s[i]]*multiplier;
        }
        return num;
    }
};
