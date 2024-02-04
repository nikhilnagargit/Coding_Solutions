class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
         int idx = k;
        int time = 1;
        int n = word.size();
        while(idx<n){
         
            string sub1 = word.substr(idx);
            string sub2 = word.substr(0,n-idx);
            if(sub1==sub2) return time;
            time++;
            idx+=k;
        }
        return time;
    }
};
