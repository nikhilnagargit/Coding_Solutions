class Solution {
public:
    

    void solve(vector<int>& v,int rowIndex,int curr){
        int temp1 = v[0];
        int temp2 = v[1];
        v.push_back(1);
        for(int i=1;i<v.size()-1;i++){
            v[i] = temp1 + temp2;
            temp1 = temp2;
            temp2 = v[i+1]; 
        }   
        
        if(curr==rowIndex){
            return;
        }
        curr=curr+1;
        solve(v,rowIndex,curr);
    }
    
    
    vector<int> getRow(int rowIndex) {
 
         vector<int> v;
         v.push_back(1);
               
        if(rowIndex==0){
            return v;
        }
        
        v.push_back(1);
        if(rowIndex==1){
            return v;
        }
         solve(v,rowIndex,2);
        
        return v;
    }
};
