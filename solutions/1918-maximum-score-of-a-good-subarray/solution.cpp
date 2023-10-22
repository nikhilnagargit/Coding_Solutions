class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k;
        int j=k;
        int mini = nums[k];
        int cost = nums[k];
        while(i-1>=0 and (j+1<nums.size())){
            int new_item;
            if(nums[i-1]>=nums[j+1]){
                new_item= nums[i-1];
                i--;
                
            }
            else{
                new_item = nums[j+1];
                j++;
                
            }
            mini = min(mini,new_item);
            cout<<"min"<<mini<<endl;
            cost = max(cost,mini*(j-i+1));
        }

        cout<<"i:"<<i;
        cout<<"j:"<<j;

        while(i>0){
            i--;
            mini = min(mini,nums[i]);
            cost = max(cost,mini*(j-i+1));
        }
        while(j+1<nums.size()){
            j++;
            mini = min(mini,nums[j]);
            cost = max(cost,mini*(j-i+1));
        }

        return cost;
    }
};
