class Solution {
public:
       void print(vector<int>& v){
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<",";
            }
            cout<<endl;
        }
    int sumSubarrayMins(vector<int>& arr) {
 
        vector<long>left(arr.size(),-1);
        vector<long>right(arr.size(),arr.size());
        stack<int> stk;
        long long ans_sum = 0;
        int mod = 1000000007;
        for(int i=0;i<arr.size();i++){
            while(!stk.empty() and arr[stk.top()]>arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stack<int> stk2;
        for(int i=arr.size()-1;i>=0;i--){
            while(!stk2.empty() and arr[stk2.top()]>=arr[i]){
                stk2.pop();
            }
            if(!stk2.empty()){
                right[i] = stk2.top();
            }
            stk2.push(i);
        }
       
        for(int i=0;i<arr.size();i++){
            ans_sum = (ans_sum + (arr[i]*((i-left[i])*(right[i]-i))%mod)%mod)%mod;
        }
        return static_cast<int>(ans_sum);
    }
};
