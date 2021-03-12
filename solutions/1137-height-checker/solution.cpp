
class Solution {
public:
    int heightChecker(vector<int>& a) {
        int c=0;
        vector<int> b=a;
        sort(b.begin(),b.end());
        for(int i=0;i<a.size();i++)
            if(a[i]!=b[i])
                c++;
        return c;
    }
};
