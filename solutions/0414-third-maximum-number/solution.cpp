class Solution {
public:

int thirdMax(vector<int>& nums) {

    
    int first  = -1;
    int second = -1;
    int third = -1;
    
    for(int i =0;i<nums.size();i++){
        
        if(first==nums[i]||second==nums[i]||third==nums[i]){
            continue;
        }
        
        if(first==-1 || nums[i]>first){
            third = second;
            second = first;
            first = nums[i];
        }
        
        else if(second==-1 || nums[i]>second){
            third = second;
            second = nums[i];
        }
        else if(third==-1 || nums[i]>third){
            third = nums[i];    
        }
        
        
    }
    
    if(third==-1){
        return first;
    }
    return third;
    
    
    }

};
