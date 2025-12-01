class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        long long extra =0;
        for(int i=0;i<batteries.size()-n;i++){
            extra += batteries[i];
        }
        vector<int>live;
        for(int i=batteries.size()-n;i<batteries.size();i++){
            live.push_back(batteries[i]);
        }
        //increase one by one, until we can increase
        for(int i=1;i<live.size();i++){
            if((live[i]-live[i-1])*(i)<=extra){
                extra = extra - (live[i]-live[i-1])*(i);
                live[i-1]=live[i];
            }
            else{
                return live[i-1]+extra/i;
            }
        }
        return live[live.size()-1]+(extra/live.size());
    }

};
