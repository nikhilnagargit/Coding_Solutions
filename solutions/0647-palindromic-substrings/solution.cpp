class Solution {
public:

    int countSubstrings(string s) {
        int ans  = 0;
        for(int l=1;l<=s.size();l++){
            for(int i=0;i<=s.size()-l;i++){
           
                int left =i;
                int right =i+l-1;
                int flag = 1;
                while(left<right){
                    if(s[left]!=s[right]){
                        flag = 0;
                        break;
                    }
                    left++;
                    right--;
                }
                ans+= flag;
            }
        }
        return ans;
    }
};
