class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if(s1[0]!=s2[0]or s2[0]!=s3[0]or s1[0]!=s3[0])return -1;
        int a = s1.size();
        int b = s2.size();
        int c = s3.size();
        int n = min(a,b);
            n = min(n,c);
        int counter = 0;
        for(int i=0;i<n;i++){
           
            if(s1[i]==s2[i] and s3[i]==s1[i]){
               
                counter++;
            }
            else{
                break;
            }
        }

        return (s1.size()+s2.size()+s3.size()-3*counter);
    }
};
