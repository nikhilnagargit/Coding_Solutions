class Solution {
public:
    long long calculate_hours(vector<int>& piles,int rate){
        long long hours = 0;
        for(int i=0;i<piles.size();i++){
            hours += piles[i]/rate;
            if(piles[i]%rate!=0){
                hours+=1;
            }
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int targetHours)
    {
        int left =  1;
        int right = *max_element(piles.begin(),piles.end());
        int mid;
        while(left<=right){
            mid = left + (right-left)/2;
            long long total_hours = calculate_hours(piles,mid);
            if(total_hours<=targetHours){
                right = mid-1;
            }
            else if(total_hours>targetHours){
                left = mid+1;
            }
        }
        return left;
    }
};
