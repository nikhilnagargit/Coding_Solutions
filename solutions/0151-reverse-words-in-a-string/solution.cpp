class Solution {
public:
    void reverse(string& s,int left,int right){
        while(left<right){
            swap(s[left],s[right]);
            left++;
            right--;
        } 
    }

    string reverseWords(string s) {
        //remove the extra space.
        int size=0;
        int i=0;
        int left=0;
        int right=0;
        while(i<s.size()){
            while(i<s.size() and s[i]==' '){
                i++;
            }
            left = size;
            while(i<s.size() and s[i]!=' '){
                s[size]=s[i];
                size++;
                i++;
            }
            right= size-1;
            reverse(s,left,right);
            if(i<s.size()){
                s[size]=' ';
                size++;
                i++;
            }
        }
        if(s[size-1]==' '){
            size--;
        }
        s.resize(size);
        reverse(s,0,size-1);
        return s;
    }
};
