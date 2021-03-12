class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i=0;
        int j=A.size()-1;
        int temp;
        while(i<j){
            while(i<j and A[i]%2==0){
                i++;
            }
            while(i<j and A[j]%2!=0){
                j--;
            }
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
        return A;
    }
};
