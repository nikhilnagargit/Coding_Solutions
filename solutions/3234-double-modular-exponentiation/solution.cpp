class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        int i=0;
        for(auto item:variables){
            int a = item[0];
            int b = item[1];
            int c = item[2];
            int m = item[3];
            int result = 1;
            for(int j=0;j<b;j++){
                result = (result*a)%10;
            }
            int temp = result;
            result = 1;
            for(int k=0;k<c;k++){
                result = (result*temp)%m;
            }
            if(result==target){
                ans.push_back(i);
            }
            i++;
        }
        return ans;
    }
};
