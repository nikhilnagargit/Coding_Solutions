class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int>ans;
        ans.push_back(1);
        if(rowIndex==0){
            return ans;
        }

        for(int i=1;i<=rowIndex;i++){
            ans.push_back(1);
            int first = ans[0];
            int second = ans[1];
            for(int j=1;j<i;j++){
                ans[j] = first+second;
                first = second;
                second = ans[j+1];
            }
        }
        return ans;
    }
};
