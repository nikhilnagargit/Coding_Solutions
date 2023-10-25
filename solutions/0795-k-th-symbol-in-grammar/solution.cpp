class Solution {
public:
    int kthGrammar(int N, int K) {
        int n=2;
        int k=K;
        bool ans=false;
        while(k>1){
            if(k<=pow(2,N-n)){
                // no change in offset, no change in k;
                n++;
            }
            else{
                k = k-pow(2,N-n);
                n++;
                ans = !ans;
            }
        }
            if(ans) return 1;
            return 0;
    }

};
