class Solution {
public:
    int kthGrammar(int N, int K) {
        
        if(N==1 or K==1){
            return 0;
        }
        int mid  = (1<<(N-1))/2;
        
        if(K<=mid){
            return kthGrammar(N-1,K); 
        }
        return !kthGrammar(N-1,K-mid);
        
    }
};
