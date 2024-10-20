class Solution {
public:
    bool parseBoolExpr(string expression) {

        // cout<<expression<<endl;
        int l = expression.size();
        if(expression.size()==1){
            return (expression[0]=='f'?false:true);
        }

        if(expression[0]=='!'){
            return !parseBoolExpr(expression.substr(2,l-3));
        }

        if(expression[0]=='&'){
    //  cout<<"inside &";
            vector<string> exp_arr;
 string exp = "";
//    cout<<" i=2, i<="<<l-2<<endl;
            int lvl = 0;
            for(int i=2;i<=l-2;i++){
            //    cout<<i<<endl;
            if(expression[i]=='('){
                lvl++;
            }
            if(expression[i]==')'){
                lvl--;
            }
                if(expression[i]==',' & lvl==0){
                    exp_arr.push_back(exp);
                    // cout<<exp<<",";
                    exp = "";
                }
                else{
                    exp+= expression[i];
                }
            }
            exp_arr.push_back(exp);
            // cout<<endl;
          
            if(exp_arr.size()==1){
                return parseBoolExpr(exp_arr[0]);
            }
            for(int i=0;i<exp_arr.size();i++){
                if(!parseBoolExpr(exp_arr[i])){
                    return false;
                }
            }
            return true;
        }
        
        if(expression[0]=='|'){
       
            vector<string> exp_arr;
    string exp = "";
int lvl = 0;
    
            for(int i=2;i<=l-2;i++){
                  if(expression[i]=='('){
                lvl++;
            }
            if(expression[i]==')'){
                lvl--;
            }
                if(expression[i]==',' && lvl==0){
                    exp_arr.push_back(exp);
                    exp = "";
                }
                else{
                    exp+= expression[i];
                }
            }
                exp_arr.push_back(exp);

            if(exp_arr.size()==1){
                return parseBoolExpr(exp_arr[0]);
            }
            for(int i=0;i<exp_arr.size();i++){
                if(parseBoolExpr(exp_arr[i])){
                    return true;
                }
            }
            return false;
        }


        return true;
    }
};
