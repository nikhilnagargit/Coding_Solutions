class Solution {
    public void duplicateZeros(int[] arr) {
        int j;
        int i=0;
        while(i<arr.length-1){
            if(arr[i]==0){
                j=arr.length-1;
                while(j>i){
                    arr[j]= arr[j-1];
                    j--;
                }
                i++;
            }
            i++;
        }
        
        
    }
}
