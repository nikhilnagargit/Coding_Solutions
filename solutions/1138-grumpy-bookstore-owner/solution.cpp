class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int initial_result = 0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0){
                initial_result+= customers[i];
            }
        }
        int max_result = initial_result;
        // cout<<max_result<<" ";

        int left = 0;
        int right = minutes;
        int current_grumpy_count = 0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1){
                current_grumpy_count+= customers[i];
            }
        } 
        max_result = max_result+current_grumpy_count;

        // cout<<max_result<<" ";
        while(right<customers.size()){
            if(grumpy[right]==1){
                current_grumpy_count+= customers[right];
            }
            if(grumpy[left]==1){
                current_grumpy_count-= customers[left];
            }
            max_result = max(max_result,initial_result+current_grumpy_count);
            left++;
            right++;
        }

        return max_result;
    }
};
