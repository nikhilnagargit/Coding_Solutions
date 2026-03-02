class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>v(n,0);
        // fill the vector with continuous end zero counts in each row.
        for(int i=0;i<n;i++){
            int zerocount =0 ;
            int j=n-1;
            while(j>=0 and grid[i][j]==0){
                zerocount++;
                j--;
            }
            v[i]=zerocount;
        }
        // we will try to sort and move the first eligible count to target place
        int ans =0 ;
        for(int target = 0;target<=n-1;target++){
            int required_zeros = n-target-1;
            int flag =0 ;
            for(int i=target;i<n;i++){
                if(v[i]>=required_zeros){
                    flag =1;
                    // found the candidate to swap till target position
                    int swaps = i-target;
                    ans+=swaps;
                    // do the swapping
                    int j = i;
                    while(j){
                        swap(v[i],v[i-1]);
                        i--;
                        j--;
                    }
                    break;
                }
            }
            if(flag==0) return -1;
        }
        return ans;
    }
};
