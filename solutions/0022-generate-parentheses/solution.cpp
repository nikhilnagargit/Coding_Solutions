class Solution {
public:
    vector<string>ans;

    void backtracking(int& n,int& open,int& close,string& s){
        if(open==close and open+close==2*n){
            ans.push_back(s);
            return;
        }
        if(open>close){
            s = s+")";
            close = close+1;
            backtracking(n,open,close,s);
            close = close-1;
            s.pop_back();
        }
        if(open<n){
            open = open+1;
            s+="(";
            backtracking(n,open,close,s);
            open = open-1;
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s= "";
        int open = 0;
        int close = 0;
        backtracking(n,open,close,s);
        return ans;
    }
};
