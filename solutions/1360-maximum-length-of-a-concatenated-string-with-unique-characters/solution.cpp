class Solution {
public:
    int solve(vector<string>& arr, unordered_set<char> myset, int i){
        if(i>=arr.size()){
            return myset.size();
        }
        int ans = myset.size();
        unordered_set<char>myset_copy = myset;

        for(char c:arr[i]){
            if(myset_copy.find(c)!=myset_copy.end()){
                myset_copy.clear();
                break;
            }
            else{
                myset_copy.insert(c);
            }
        }
        if(myset_copy.size()==0){
            return solve(arr,myset,i+1);
        }
        else{
            return max(solve(arr,myset_copy,i+1),solve(arr,myset,i+1));
        }

    }
    int maxLength(vector<string>& arr) {
        unordered_set<char>myset;
        return solve(arr,myset,0);
    }
};
