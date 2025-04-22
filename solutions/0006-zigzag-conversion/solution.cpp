class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>>v(numRows,vector<char>(1000,' ')) ;

        int index = 0;
        int n = 0;
        int m = 0;
        while(index<s.size()){
            for(int i=0;i<numRows;i++){
                if(index<s.size()){
                     
                //   cout<<n<<","<<m<<","<<index<<endl;
              
                    v[n][m] = s[index];
                    n = n+1;
                    index++;
                }
            }
            n = numRows-1;
            // cout<<"--------"<<endl;
            for(int i=1;i<numRows-1;i++){
                if(index<s.size()){
                    n = n-1;
                    m = m+1;
            //    cout<<n<<","<<m<<","<<index<<endl;
                    v[n][m] = s[index];
                    index++;
                }
            }
            n = 0;
            m = m+1;
        }

        string ans= "";
        
        for(int i=0;i<numRows;i++){
            for(int j=0;j<1000;j++){
                if(v[i][j]!=' '){
                    ans+= v[i][j];
                }
            }
        }
        return ans;
    }
};

