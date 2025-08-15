class Solution {
public:
    int climbStairs(int n) {
       vector<int> dp(n+1,0);
       int last = 1;
       int lastlast = 1;
       for(int i=2;i<=n;i++) {
          int temp = last+lastlast;
          lastlast=last;
          last=temp;
       }
       return last;
    }
};
