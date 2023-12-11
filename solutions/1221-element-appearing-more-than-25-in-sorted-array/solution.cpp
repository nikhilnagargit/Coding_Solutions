class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int prev = arr[0];
        int countlimit = arr.size()/4  +1;
        int count = 1;
        for(int j=1;j<arr.size();j++){
            int i= arr[j];
            if(prev==i){
                count++;
            }
            else{
                count =1;
            }
            if(count>=countlimit){
                return i;
            }
            prev = i;
        }
        return arr[0];
    }
};
