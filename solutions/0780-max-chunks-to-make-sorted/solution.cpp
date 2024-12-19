class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0;
        unordered_set<int> covered;
        int lastclear = -1;
        for(int i=0;i<arr.size();i++){
            bool flag = true;
            covered.insert(arr[i]);
            for(int j=lastclear+1;j<=i;j++){
                if(covered.count(j)==0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                chunks++;
                lastclear = i;
                covered.clear();
            }
        
        }
        return chunks;
    }
};
