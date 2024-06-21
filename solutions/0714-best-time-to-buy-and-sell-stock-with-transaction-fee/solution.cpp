class Solution {
public:
     unordered_map<string,int>m;
//action  = 0 buy, action = 1 i will sell
    int solve(vector<int>&prices, int& fee, int idx,int action)
    {
        if(idx==prices.size()-1 and action==1){
             return prices[idx]-fee; 
        }

        if(idx==prices.size()-1 and action==0){
             return 0;
        }
       string key = to_string(idx)+"-"+to_string(action);
      if(m.find(key)!=m.end()){
            return m[key];
        }

int case1  = 0;
int case2 = 0;
int case3 = 0;

        if(action==0){
            //i can buy current index stock
            case1 = solve(prices,fee,idx+1,1) - prices[idx];
            //i can skip
        }

        if(action==1){
            //i can sell current stock
            case2 = solve(prices,fee,idx+1,0)-fee+prices[idx];
    

        }
        case3 = solve(prices,fee,idx+1,action);

        return m[key]=max(case1,max(case2,case3));


    }
    int maxProfit(vector<int>& prices, int fee) {
     return solve(prices,fee,0,0);   
    }
};
