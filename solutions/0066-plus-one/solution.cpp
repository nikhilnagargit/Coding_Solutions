class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size()==0){
            return vector<int>({1});
        }
        int carry = 0;
        if(digits[digits.size()-1]+1 >=10){
            carry = digits[digits.size()-1]-10;
        }
        if(!carry){
            digits[digits.size()-1] +=1;
            return digits;
        }
        vector<int> newv(digits.begin(),digits.end()-1);
        newv = plusOne(newv);
        newv.push_back(0);
        return newv;
    }
};
