class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i=0;
        while(i<gas.size()){
            int tank = gas[i];
            bool flag = true;
            // cout<<i<<"--"<<endl;
            for(int j=0;j<gas.size();j++){
                if(tank<cost[(i+j)%n]){
                    flag = false;
                    i = i+j;
                    break;
                }
                else{
                    tank += gas[(i+j+1)%n] - cost[(i+j)%n];
                }
                // cout<<tank<<",";
            }
            // cout<<endl;
            i++;
            if(flag)
            return i-1;
        }
        return -1;
    }
};
