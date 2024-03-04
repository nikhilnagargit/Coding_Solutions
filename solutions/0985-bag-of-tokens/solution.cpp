class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int left = 0;
        int right = tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        int score = 0;
        int maxscore = 0;
        while(left<=right){
            bool flag = false;
            while(left<=right and power-tokens[left]>=0){
                power = power-tokens[left];
                left++;
                score++;
                maxscore = max(maxscore,score);
                flag = true;
            }
            while(left<=right and score>0 and power-tokens[left]<0){
                power += tokens[right];
                score--;
                right--;
                flag = true;
            }
            if(!flag)break;
        }
        return maxscore;
    }
};
