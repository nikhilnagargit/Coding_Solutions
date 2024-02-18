class Solution {
public:
    void solve(vector<vector<int>>& mat,int i,int j, vector<int>& dir,unordered_map<int,int>& map,int num){
        if(i<0 or j<0 or i>=mat.size() or j>=mat[0].size()){
            return;
        }
        num = num*10 + mat[i][j];
        if(num>10 and num%2!=0)
            map[num]++;
        solve(mat,i+dir[0],j+dir[1],dir,map,num);
        
    }
    
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        unordered_map<int,int> map;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int d = 0;d<directions.size();d++){
                    solve(mat,i,j,directions[d],map,0);
                }
            }
        }
        
        
         bool prime[1000001];
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= 1000000; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= 1000000; i += p)
                    prime[i] = false;
            }
        }
        
        int maxprime = -1;
        int maxprimecount = 0;
        for(auto i:map){
            if(prime[i.first] and (i.second>maxprimecount or (i.second==maxprimecount and i.first>maxprime))){
                maxprime = i.first;
                maxprimecount = i.second;
            }
        }
        
        return maxprime;
    }
};
