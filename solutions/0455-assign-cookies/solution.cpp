class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());
        int a = 0;
        int b = 0;
        while(a<g.size() and b<s.size()){
            if(g[a]<=s[b]){
                a++;
                b++;
            }
            else{
                a++;
            }
         
        }
        return b;
    }
};
