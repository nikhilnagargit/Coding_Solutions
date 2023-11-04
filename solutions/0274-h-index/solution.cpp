class Solution {
public:
    int hIndex(vector<int>& citations) {

        sort(citations.begin(),citations.end(),greater<int>());
        
 
        int left = 0;
        int right = citations.size()-1;

        while(left<right){
            int mid = left+(right-left)/2;
            if(citations[mid]==mid+1){
                return mid+1;
            }
            else if(citations[mid]<mid+1){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        if(citations[left]>=left+1) return left+1;

        return left;
        }
        
};
