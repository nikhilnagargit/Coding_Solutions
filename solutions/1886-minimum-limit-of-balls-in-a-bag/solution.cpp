class Solution {
public:
    bool find(vector<int>&nums,int& maxBagOperations,int maxBagLimit){
        int op = 0;
        for(int& n:nums){
            if(n<=maxBagLimit){
                continue;
            }
            // op+= n/maxBagLimit+((n%maxBagLimit>0)?1:0);
            op+= ceil(n/(double)maxBagLimit)-1;
            if(op>maxBagOperations){
            return false;
        }
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = 1000000001;

        while(left<right){
            int mid  = left + (right-left)/2;
            // cout<<mid<<endl;
            if(find(nums,maxOperations,mid)){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};
