class Solution {
public:
    int pivotInteger(int n) {
        int total_sum = (n*(n+1))/2;
        int sum = 0;
        for(int pivot=1;pivot<=n;pivot++){
            sum+= pivot;
            if(sum==total_sum-sum+pivot){
                return pivot;
            }
        }
        return -1;
        
    }
};
