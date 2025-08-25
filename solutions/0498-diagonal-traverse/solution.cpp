class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat[0].size();
        int n = mat.size();
        for(int diagnum=0;diagnum<m+n-1;diagnum++){
            if(diagnum%2==0){
                //upwards
                //i will be diagnum until it does not exceed width of m
                int i = diagnum;
                if(i > n-1){
                    i = n-1;
                }
                
                //j will be 0 until we exceed  middle diag of height n
                int j = 0;
                if(diagnum>n-1){
                    j = diagnum-n+1;
                }

                //try and push until index become invalid
                while(i<n and j<m and i>=0 and j>=0){
                    ans.push_back(mat[i][j]);
                    i = i-1;
                    j = j+1;
                }
            }
            else{
                //downwards
                int i=0;
                if(diagnum>m-1){
                    i = diagnum-m+1;
                }

                int j=diagnum;
                if(diagnum>m-1){
                    j = m-1;
                }

                //try and push until index become invalid
                while(i<n and j<m and i>=0 and j>=0){
                    ans.push_back(mat[i][j]);
                    i = i+1;
                    j = j-1;
                }
            }
        }

        return ans;
    }
};
