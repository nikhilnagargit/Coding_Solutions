class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int last = arr.size()-1;
        int maxi = arr[last];
        int temp;
        arr[last] =-1;
        for(int i=last-1;i>=0;i--){
            temp = maxi;
            maxi = max(arr[i],maxi);
            arr[i] = temp;
        }

        return arr;
    }
    
};
