class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // monotonik stack of time taken until target
        stack<int> stk;
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        vector<double> times;
        for(auto& p:v){
            times.push_back((target-(double)p.first)/(double)p.second);
            // cout<<*(times.end()-1)<<",";
        }
        double prevLargest = -100000000;
        int count = 0;
        for(int i=times.size()-1;i>=0;i--){

            if(times[i]>prevLargest){
                count++;
                prevLargest = times[i];
                // cout<<prevLargest<<",";
            }
        }
        return count;
    }
};
