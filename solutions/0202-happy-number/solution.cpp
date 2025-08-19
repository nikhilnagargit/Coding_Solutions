class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> m;
        while(true){
            int sum = 0;
            if(n==1){return true;}
            if(m.count(n))return false;
            m.insert(n);
            while(n){
                int rem = n%10;
                n = n/10;
                sum+=rem*rem;
            }
            n = sum;
        }
    }
};
