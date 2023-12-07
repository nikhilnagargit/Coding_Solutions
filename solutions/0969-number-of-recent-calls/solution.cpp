class RecentCounter {
public:
    vector<int> requests;
    RecentCounter() {
    }

    
    int ping(int t) {
        requests.push_back(t);
        int count = 0;
        int left = t-3000;
        for(int i=requests.size()-1;i>=0;i--){
            if(requests[i]>=left){
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
