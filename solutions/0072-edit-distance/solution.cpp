class Solution {
public:
    int solve(int i,int j, string& w1,string& w2,vector<vector<int>>&m){
        if(j==w2.size())return (w1.size()-i);
        if(i==w1.size())return (w2.size()-j);
        if(m[i][j]!=-1){
            return m[i][j];
        }
        if(w1[i]==w2[j]){
            return m[i][j]=solve(i+1,j+1,w1,w2,m);
        }
        return m[i][j]=1+min(solve(i,j+1,w1,w2,m),min(solve(i+1,j+1,w1,w2,m),solve(i+1,j,w1,w2,m)));
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> m (word1.size()+1,vector<int>(word2.size()+1,-1));
        return solve(0,0,word1,word2,m);
    }
};
