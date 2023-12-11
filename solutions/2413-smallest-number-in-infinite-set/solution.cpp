class SmallestInfiniteSet {
public:
    set<int>s;
    priority_queue<int,vector<int>,greater<int>>pq;
    SmallestInfiniteSet() {
        pq.push(1);
        s.insert(1);
    }
    int popSmallest() {
        int ans = pq.top();
        s.erase(ans);
        pq.pop();
        if(pq.size()==0){
            pq.push(ans+1);
            s.insert(ans+1);
        } 
        return ans;
    }
    
    void addBack(int num) {
        if(s.find(num)==s.end() and num<(*(s.rbegin())))
           {
            pq.push(num);
            s.insert(num);
            }
             
        }
        
    
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
