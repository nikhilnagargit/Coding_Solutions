class Solution {
public:
    static int numberOfBits(int i){
        int count=0;
        while(i){
            if(i&1){
                count++;
            }
            i = i>>1;
        }
        return count;
    }

    static bool compare(int a,int b){
        int i = numberOfBits(a);
        int j = numberOfBits(b);
        if(i==j){
            return a<b;
        }
        return i<j;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};
