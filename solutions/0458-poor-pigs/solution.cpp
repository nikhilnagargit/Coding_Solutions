class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int ans = 0;
        int T = minutesToTest/minutesToDie;
        for(int i=0;i<=buckets;i++){
            if(pow(T+1,i)>=buckets){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
