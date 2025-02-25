class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long MOD = 1e9+7;
        int oddCount = 0;
        int evenCount = 0;
        int ans = 0;

        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0){
                evenCount++;
            }
            else{
                swap(oddCount,evenCount);
                oddCount++;
            }
            ans = (ans+oddCount%MOD)%MOD;
        }
        return ans;
    }
};
