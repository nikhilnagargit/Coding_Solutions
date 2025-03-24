class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;
        sort(meetings.begin(),meetings.end());
        // for(auto item:meetings){
        //     cout<<item[0]<<","<<item[1]<<endl;
        // }
        int maxi = meetings[0][1];
        int mini = meetings[0][0];
        for(int i=1;i<meetings.size();i++){
            int a = meetings[i-1][0];
            int b = meetings[i-1][1];
            int c = meetings[i][0];
            int d = meetings[i][1];
            if(b<=days and c<=days and b<c){
                ans+= c-b-1;
            }
            if(b>c and b>d){
                meetings[i][1] = b; 
            }
            if(b>days or c>days){
                break;
            }
            maxi = max(maxi,d);
            mini = min(mini,c);
        }
        if(maxi<days){
            ans += days-maxi;
        }
        if(mini>1){
            ans += mini-1;
        }

        return ans;
    }
};
