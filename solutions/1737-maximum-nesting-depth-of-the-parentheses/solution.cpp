class Solution {
public:
    int maxDepth(string s) {
        int left_par_count = 0;
        int maxcount = 0;
        for(char c:s){
            if(c=='('){
                left_par_count++;
            }
            else if(c==')'){
                left_par_count--;
            }
            maxcount = max(maxcount,left_par_count);
        }
        return maxcount;
    }
};
