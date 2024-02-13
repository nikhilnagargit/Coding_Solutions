class Solution {
public:
    bool checkp(string w){
   
            int left=0;
            int right = w.size()-1;
            while(left<right){
                if(w[left]!=w[right]){
                    return false;
                }
                left++;
                right--;
            }
   
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto w:words){
            if(checkp(w)) return w;
        }
        return "";
    }
};
