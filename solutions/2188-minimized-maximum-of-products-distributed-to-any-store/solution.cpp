class Solution {
public:

    bool isPossible(vector<int>& arr, int k, int n){
        int count = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%k==0){
                count+= arr[i]/k;
            }
            else{
                count+= arr[i]/k+1;
            }
        }
        if( count<=n){
            return true;
        }
        return false;
    }

    int minimizedMaximum(int n, vector<int>& q) {
        int s=1,e=100000,ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(q,mid,n)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
