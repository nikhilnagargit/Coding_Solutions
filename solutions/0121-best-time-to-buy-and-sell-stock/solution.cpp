class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini =0 ;
        int max_diff = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<arr[mini]){
                mini = i;
            }
            else{
                if(max_diff<arr[i]-arr[mini]){
                    max_diff = arr[i]-arr[mini];
                }
            }
        }
        return max_diff;
    }
};
