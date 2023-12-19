class Solution {
public:
    vector<int>deltai = {1,-1,0,0,1,1,-1,-1};
    vector<int>deltaj = {0,0,1,-1,1,-1,1,-1};
    int get(vector<vector<int>>&img,int i,int j){
        int m = img.size();
        int n = img[0].size();
        if(i<0 or j<0 or i>=m or j>=n){
            return -1;
        }
        return img[i][j];
    }
    int getavg(vector<vector<int>>&img,int i,int j){
        int sum  = img[i][j];
        int count = 1;
        for(int k=0;k<8;k++){
            int temp = get(img,deltai[k]+i,deltaj[k]+j);
            if(temp!=-1){
                sum+=temp;
                count++;
                cout<<temp<<",";
            }
        }
        cout<<endl;
        return sum/count;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size(),vector<int>(img[0].size(),0));
        for(int i=0;i<img.size();i++){
            for(int j=0;j<img[0].size();j++){
                ans[i][j] = getavg(img,i,j);
            }
        }
        return ans;
    }
};
