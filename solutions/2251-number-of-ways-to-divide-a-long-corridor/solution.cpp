class Solution {
public:
    int numberOfWays(string corridor) {
        int mod   = 1000000007;
        // count the seats and if they are odd, return 0
        int seatCount =0;
        for(auto c:corridor) if(c=='S') seatCount++;
        if(seatCount%2!=0 or seatCount==0){
            return 0;
        }
        if(seatCount==2)return 1;

        // make the pair of indexes of seat pairs from begin to end
        vector<pair<int,int>> seatPositionsPairs;
        int i=0;
        int n = corridor.size();
        int firstSeatIndex = -1;
        int secondSeatIndex = -1;
        while(i<n){
            if(corridor[i]=='S' and firstSeatIndex==-1){
                firstSeatIndex = i;
                i++;
            }
            else if(corridor[i]=='S' and secondSeatIndex==-1){
                secondSeatIndex = i;
                i++;
            }
            else if(corridor[i]=='P'){
                i++;
            }
            if(firstSeatIndex!=-1 and secondSeatIndex!=-1){
                seatPositionsPairs.push_back({firstSeatIndex,secondSeatIndex});
                firstSeatIndex = -1;
                secondSeatIndex = -1;
            }
        }

        long long count =1 ;
        int N = seatPositionsPairs.size();
        for(int i=1;i<N;i++){
            int firstEnd = seatPositionsPairs[i-1].second;
            int secondStart = seatPositionsPairs[i].first;
            count = (count*(secondStart-firstEnd))%mod;
        }
        return count%mod;
    }
};
