class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> m;
    TimeMap() {
        
    }
    void set(string key, string value, int timestamp) {
        m[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end()){
            return "";
        }
        //check if ask exceeds latest timestamp
        auto item = m[key][m[key].size()-1];
        if(item.second<=timestamp){
            return item.first;
        }

        //find the upperbound then return
        int left = 0;
        int right = m[key].size()-1;

        while(left<=right){
            int mid = left + (right-left)/2;
            if(timestamp==m[key][mid].second){
                return m[key][mid].first;
            }
            else if(timestamp<m[key][mid].second){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        if(right<0) return "";
        return m[key][right].first;

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);


 key1 -> foo,1,   goo, 2.    fire 3


 get(key1, 2) -> goo
 get(key1, 5) -> fire

 put(key1, 1, choo)

 key1 -> choo,1  goo,2  fire,3
 get(key1,1) -> choo 

 */
