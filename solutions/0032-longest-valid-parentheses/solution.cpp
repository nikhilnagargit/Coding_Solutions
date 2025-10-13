class Solution {
public:
int longestValidParentheses(string s) {
    int open =0;
    int close = 0;
    int best = 0;

    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            open++;
        }
        else{
            close++;
        }
        if(open==close){
            best = max(best,2*open);
        }
        else if(open<close){
            open = 0;
            close = 0;
        }
    }
    open = 0;
    close= 0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]==')'){
            close++;
        }
        else{
            open++;
        }
        if(open==close){
            best = max(best,2*open);
        }
        else if(open>close){
            open = 0;
            close = 0;
        }
    }

    return best;

}

};
