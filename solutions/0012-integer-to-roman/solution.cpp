class Solution {
public:
    string intToRoman(int num) {

        vector<pair<int,string>> m = {{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};

        string ans;
        // while(num>0){
            for(auto item:m){
                // cout<<item.first;
                while(item.first<=num){
                    num = num - item.first;
                    ans += item.second;
                }
            }
        // }
        return ans;
}
        
};
