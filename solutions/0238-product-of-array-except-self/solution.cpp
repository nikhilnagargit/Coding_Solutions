class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftprod(nums.size(),1);
        vector<int> rightprod(nums.size(),1);
        leftprod[0]=nums[0];
        cout<<leftprod[0]<<",";
        for(int i=1;i<nums.size();i++){
            leftprod[i]=leftprod[i-1]*nums[i];
            cout<<leftprod[i]<<",";
        }
        cout<<endl;

        rightprod[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            rightprod[i]=rightprod[i+1]*nums[i];
        }
        for(int i=0;i<nums.size();i++){
            cout<<rightprod[i]<<",";
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int value;
            if(i==0) value = rightprod[i+1];
            else if(i==nums.size()-1) value = leftprod[i-1];
            else value = leftprod[i-1]*rightprod[i+1];
            ans.push_back(value);
        }
        return ans;
    }
};
