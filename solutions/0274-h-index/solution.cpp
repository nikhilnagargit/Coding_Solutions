class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int prev = 0;
        for(int h=citations.size()-1;h>=0;h--){
            int c = citations[h];
            int n = citations.size()-h;
            if (c>=n){
               prev = n;
            }
            else{
                break;
            }

        }
        return prev;
    }
};
