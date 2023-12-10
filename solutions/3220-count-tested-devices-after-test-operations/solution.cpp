class Solution {
public:
    int countTestedDevices(vector<int>& arr) {
        int minusfactor = 0;
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            arr[i] = max(0,arr[i]-minusfactor);
            if(arr[i]==0){
      
                continue;
            }
            else{
                ans++;
                minusfactor++;
            }

        }

        
        return ans;
    }
};
