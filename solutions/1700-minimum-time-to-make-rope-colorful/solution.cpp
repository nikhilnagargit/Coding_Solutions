class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = neededTime[0];
        int maxi = neededTime[0];
        int cost = 0 ;
        for(int i=1;i<colors.size();i++){
            if(colors[i-1]!=colors[i]){
                //caclulate cost
                cost += sum-maxi;
                //reset
                sum = neededTime[i];
                maxi = neededTime[i];
            }
            else{
                sum+= neededTime[i];
                maxi = max(maxi,neededTime[i]);
            }
        }
        cost += sum-maxi;
        return cost;
    }
};
