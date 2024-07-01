class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        //fill the sliding window
        int count = 0;
        int idx = 0;
        if(arr.size()<3){
            return false;
        }
        while(idx<3){
            if(arr[idx]%2!=0){
                count++;
            }
            idx++;
        }
        if(count==3){
                return true;
        }
        //start traversing through sliding window
        int left = 0;
        while(idx<arr.size()){
            if(arr[idx]%2!=0){
                count++;

            }
            if(arr[left]%2!=0){
                count--;
                left++;
            }
             idx++;
            if(count==3){
                return true;
            }
        }

        return false;
    }
};
