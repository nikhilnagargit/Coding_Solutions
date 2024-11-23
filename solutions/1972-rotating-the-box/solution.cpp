class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        for(int i=0;i<m;i++){
            vector<int> v(n+1,-1);
            int prev_block = n;
            int count = 0;
            for(int j=n-1;j>=0;j--){
                if(box[i][j]=='*'){
                    v[prev_block] = count;
                    count = 0;        
                    prev_block = j;
                }
                else if(box[i][j]=='#'){
                    count++;
                }
            }
            v[prev_block] = count;

            //print v vector
            // for(auto i:v){
            //     cout<<i<<",";
            // }
            // cout<<endl;

            count = v[n];

            for(int j=n-1;j>=0;j--){
                if(v[j]!=-1){
                    count= v[j];
                    continue;
                }
                if(count>0){
                    box[i][j] = '#';
                    count--;
                }
                else{
                    box[i][j] = '.'; 
                }
            }
        }



        vector<vector<char>> ans (n, vector<char>(m,'.'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = box[m-j-1][i];
            }
        }

        return ans;


    }
};
