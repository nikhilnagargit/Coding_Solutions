class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int max_zor = INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int x =  nums[i];
                int y = nums[j];
                if(abs(x-y)<=min(x,y)){
                   
                    if((x^y)>max_zor){
                        max_zor = x^y;
                    }
                }
            }
            
        }
      
        return max_zor;
    }
};
