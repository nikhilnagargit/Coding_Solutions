class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {

        int c = m+n-1;
        
        if(m==0){
            for(int i=0; i<n; i++){
                nums1[i] = nums2[i];
            }
        }
        
        else if(n==0){
            
        }
         else{
             int i=m-1;
             int j=n-1;
             
        while(c>=0 && i>=0 && j>=0 ){
            if(nums1[i]>=nums2[j]){
                nums1[c] = nums1[i];
                i--;
                c--;
            }
            else{
                nums1[c] = nums2[j];
                j--;
                c--;
            }
        }
             
             while(c>=0 && i>=0){
                 nums1[c] = nums1[i];
                 c--;
                 i--;
             }
             
             
             while(c>=0 && j>=0){
                 nums1[c] = nums2[j];
                 j--;
                 c--;
             }
             
         }
    
    }
}
