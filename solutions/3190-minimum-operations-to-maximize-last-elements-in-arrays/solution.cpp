class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        // find ans without swap
        int result1 = 0;
        for(int i=0;i<n-1;i++){
            if(nums1[i]<=nums1[n-1] and nums2[i]<=nums2[n-1]){
                // no need to swap;
            }
            else if(nums1[i]<=nums2[n-1] and nums2[i]<=nums1[n-1]){
                result1++;
            }
            else{
                result1 = -1;
                break;
            }
        }


        // find ans with swapping last elements;
        swap(nums1[n-1],nums2[n-1]);
        int result2 = 1;
        for(int i=0;i<n-1;i++){
            if(nums1[i]<=nums1[n-1] and nums2[i]<=nums2[n-1]){
                // no need to swap;
            }
            else if(nums1[i]<=nums2[n-1] and nums2[i]<=nums1[n-1]){
                swap(nums1[i],nums2[i]);
                result2++;
            }
            else{
                result2 = -1;
                break;
            }
        }

        if(result1==-1) return result2;
        if(result2==-1) return result1;

        return(min(result1,result2));
    }
};
