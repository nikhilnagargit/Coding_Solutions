class Solution {
public:
    bool solve(int& n,int& k,int& curr_number,string& ans){

        if(ans.size()==n){
            curr_number++;
            if(curr_number==k){
                return true;
            }
            return false;
        }

        if(ans=="" or ans[ans.size()-1]!='a'){
            ans = ans+"a";
            if(solve(n,k,curr_number,ans)){return true;}
            ans.pop_back();
        }

        if(ans=="" or ans[ans.size()-1]!='b'){
            ans = ans+"b";
            if(solve(n,k,curr_number,ans)){return true;}
            ans.pop_back();
        }
        if(ans=="" or ans[ans.size()-1]!='c'){   
            ans = ans+ "c";
            if(solve(n,k,curr_number,ans)){return true;}
            ans.pop_back();
        }
        return false;
    }
    string getHappyString(int n, int k) {
        string ans = "";
        int curr_number = 0;
        solve(n,k,curr_number,ans);
        // if(!solve(n,k,curr_number,ans)){ans="";}
        return ans;
    }
};
