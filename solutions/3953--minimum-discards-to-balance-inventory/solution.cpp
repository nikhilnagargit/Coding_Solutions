class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int M) {
        int count = 0;
        int left=0;
        unordered_map<int,int> m;
        for(int right=0;right<arrivals.size();right++){
            m[arrivals[right]]++;
            if(m[arrivals[right]]>M){
                //discard this
                m[arrivals[right]]--;
                arrivals[right] = -1* arrivals[right];
                count++;
            }
            //move the window
            if(right-left+1 >= w){
            if(arrivals[left]>0) {
                m[arrivals[left]]--;
            }
            if(m[arrivals[left]]==0){
                m.erase(arrivals[left]);
            }
                        //move left
            left++;
            
            }
    
        }

        return count;
    }
};
