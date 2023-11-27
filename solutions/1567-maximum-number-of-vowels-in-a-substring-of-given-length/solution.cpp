class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0;
        int right = k;
        int count = 0;
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                count++;
            }
        }

        int maxi = count;
        while(right<s.size()){
            if(s[right]=='a'||s[right]=='e'||s[right]=='i'||s[right]=='o'||s[right]=='u'){
                count++;
            }
            if(s[left]=='a'||s[left]=='e'||s[left]=='i'||s[left]=='o'||s[left]=='u'){
                count--;
            }
            right++;
            left++;
            maxi = max(maxi,count);
        }
        return maxi;
    }
};
