class Solution {
public:
    bool checkCount(vector<int>& candies, long long k, int i){
        long long count = 0;
        for(auto& c:candies){
            count += c/i;
        }
        if(count<k){
            return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int left = 0;
        int right = 10e7;

        while(left<=right){
            int mid = left+ (right-left)/2;
            if(mid==0){
                return 0;
            }
            if(checkCount(candies,k,mid)){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        return right;
    }
};



