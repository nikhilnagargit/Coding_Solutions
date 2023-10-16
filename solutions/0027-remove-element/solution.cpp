class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int i=0;
        int j=0;
        int k=0;

        while(i<arr.size() and j<arr.size()){
            while(j<arr.size() and arr[j]==val){
                j++;
                k++;
            }
            if(i<arr.size() and j<arr.size()){
            arr[i]=arr[j];
            j++;
            i++;
            }
        
        }
        return arr.size()-k;
    }
};
