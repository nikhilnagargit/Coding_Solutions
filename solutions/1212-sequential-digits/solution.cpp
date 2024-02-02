class Solution {
public:
    int countDigits(int i){
        int count  =0 ;
        while(i!=0){
            i = i/10;
            count++;
        }
        return count;
    }

    int createItem(int digits,int offset){
        int ans;
        string s = "";
        for(int i=1+offset;i<=digits+offset;i++){
            s+= to_string(i);
        }
        ans = stoi(s);
        return ans;
        }
    

    vector<int> sequentialDigits(int low, int high) {
        int a = countDigits(low);
        int b = countDigits(high);
        vector<int>ans;
        for(int digits=a;digits<=b;digits++){
            for(int k = 0;k<10-digits;k++){
                int item = createItem(digits,k);
                if(item>=low and item<=high){
                    ans.push_back(item);
                }
            }
        }
        return ans;
    }
};
