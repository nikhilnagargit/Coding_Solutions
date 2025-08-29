class DetectSquares {
public:
    unordered_map<string,int> m;
    vector<vector<int>> v;
    DetectSquares() {
        
    }
    string hash(vector<int>point){
        return to_string(point[0])+'-'+to_string(point[1]);
    }
    void add(vector<int> point) {
        v.push_back(point);
        m[hash(point)]++;
    }
    
    int count(vector<int> point) {
        int count = 0;
        for(int i=0;i<v.size();i++){
            //fix one point of horizontal match
            if(v[i][1]==point[1]){
                int side = abs(v[i][0]-point[0]);
                if(side>0){
                    //above
                    string a = hash({v[i][0],v[i][1]+side});
                    string b = hash({point[0],point[1]+side});
                    if(m.count(a)!=0 and m.count(b)!=0){
                        count+= m[a]*m[b];
                    }
                    //below
                    if(v[i][1]-side >=0){
                        string a = hash({v[i][0],v[i][1]-side});
                        string b = hash({point[0],point[1]-side});
                        if(m.count(a)!=0 and m.count(b)!=0){
                            count+= m[a]*m[b];
                        }
                    }
                }
            }
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
