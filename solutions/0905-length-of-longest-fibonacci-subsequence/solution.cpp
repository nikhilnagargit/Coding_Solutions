class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxSize = 2;

        if(arr.size()==0){
            return 0;
        }
        if(arr.size()==1){
            return 0;
        }
        unordered_set<int> existing (arr.begin(),arr.end());

int curr = -1;
int prev = -1;
        for(int i=0;i<arr.size();i++){
               prev = arr[i];
            for(int j=i+1;j<arr.size();j++){
                // cout<<i<<"-"<<j<<" => ";
                 curr = arr[j];
                // cout<<prev<<","<<curr<<" - ";
                int count = 2;
                int result = existing.count(curr+prev);
                // cout<<endl;
                int p = prev;
                int c= curr;
                while(result){
                    int newSum = c+p;
                    p = c;
                    c = newSum;
                    count++;
                    result = existing.count(newSum+p);
                    // cout<<"result-"<<result<<",";
                }
                // cout<<'-';
                maxSize = max(maxSize,count);
                // cout<<count<<endl;
            }
        }
        return maxSize>2?maxSize:0;
    }
};
