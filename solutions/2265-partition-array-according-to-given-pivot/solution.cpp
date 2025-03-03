class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> bigger;
        int pivotCount = 0;

        for(int& i:nums){
            if(i<pivot){
                smaller.push_back(i);
            }
            else if(i==pivot){
                pivotCount++;
            }
            else{
                bigger.push_back(i);
            }
        }
        for(int i=0;i<smaller.size();i++){
            nums[i] = smaller[i];
        }
        int i=0;
        while(i<pivotCount){
            nums[smaller.size()+i] = pivot;
            i++;
        }
        for(int i=0;i<bigger.size();i++){
            nums[smaller.size()+pivotCount+i] = bigger[i];
        }
        return nums;
    }
};
