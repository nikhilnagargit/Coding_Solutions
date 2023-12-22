class Solution {
public:
    int maxScore(string s) {
        int countOfOnes = 0;
        for(auto c:s){
            if(c=='1') countOfOnes++;
        } 
        int maxscore = 0;
        int leftpart=0;
        int  rightpart= countOfOnes;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                leftpart++;
            }
            else if(s[i]=='1'){
                rightpart--;
            }
            maxscore = max(maxscore,leftpart+rightpart);
        }
        return maxscore;
    }
};
