class Router {
public:
    deque<vector<int>> dq;
    unordered_set<string> s;
    unordered_map<int,deque<int>> m;
    int limit;
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    string encode(vector<int> v){
        return to_string(v[0])+'-'+to_string(v[1])+'-'+to_string(v[2]);
    }

    bool addPacket(int source, int destination, int timestamp) {
        //already a copy return false
        if(s.count(encode({source,destination,timestamp}))){
            return false;
        }
        //size exceeding, remove the existing first
        if(limit==dq.size()){
            forwardPacket();
        }
        //add
        dq.push_back({source,destination,timestamp});
        m[destination].push_back(timestamp);
        s.insert(encode({source,destination,timestamp}));
        return true;

    }
    
    vector<int> forwardPacket() {
        if(dq.size()==0){
            return {};
        }
        vector<int> ans = dq.front();
        dq.pop_front();
        int timestamp = ans[2];
        int destination = ans[1];
        m[destination].pop_front();
        s.erase(encode(ans));
        return ans;
    }
    
    int getCount(int destination, int startTime, int endTime) {
 
        int leftboundary = lower_bound(m[destination].begin(),m[destination].end(),startTime) - m[destination].begin() ;
        int rightboundary = upper_bound(m[destination].begin(),m[destination].end(),endTime) - m[destination].begin() ;
        // cout<<rightboundary;
        return rightboundary-leftboundary;
    }

};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
