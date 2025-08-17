class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& s, int k) {
        long long pf = 0;
        long long maxpf = -1000000000000000000;
        int n = prices.size();
        for(int i=0;i<n;i++){
            pf+= prices[i]*s[i];
        }

        maxpf = max(maxpf,pf);
        //calculate for first window
        for(int i=0;i<k/2;i++){
            // remove first k/2 profits or losses
            pf = pf - prices[i]*s[i];
        }

        for(int i=k/2;i<k;i++){
            //add second half profits wether they were added first or not
            pf = pf + prices[i] - prices[i]*s[i];
        }
        maxpf = max(maxpf,pf);
        //go for next windows
        int left = 0;
        int mid = k/2;
        for(int right=k;right<n;right++){
            // add curr right as 1 and remove prev contribution
            pf = (long long)pf + (long long)prices[right] - (long long)prices[right]*s[right];
            // next boundary should be exclueded which was already included due to 1
            pf = (long long)pf - (long long)prices[mid];
            //last left should be included again
            pf = (long long)pf + (long long)prices[left]*s[left];
            left++;
            mid++;
            //calc max
            maxpf = max(maxpf,pf);
        }
        return maxpf;
    }
};

