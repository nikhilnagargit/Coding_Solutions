class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi=0;
        for(int i=0;i<left.size();i++){
            if(maxi<left[i]) maxi = left[i];
        }
        for(int i=0;i<right.size();i++){
            if(maxi<n-right[i])maxi = n-right[i];
        }
        return maxi;
    }
};
