class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        //check for edge case
        if(hand.size()%groupSize !=0) return false;

        map<int,int> m;
        for(auto& h:hand){
            m[h]++;
        }
        //start greedy from smallest and start deleting
        while(!m.empty()){
        //    cout<< hand.size()<<",";
            //take smallest from map
            int smallest = (*m.begin()).first;
            // cout<<smallest<<",";
            for(int i=0;i<groupSize;i++){
                int curr = smallest+i;
                if(m.find(curr)==m.end()) return false;
                m[curr]--;
                if(m[curr]<=0){
                    m.erase(curr);
                }
            }
        }
        return true;

    }
};
