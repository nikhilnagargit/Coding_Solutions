class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(s.count(val)){
            return false;
        }
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.count(val)){
            s.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
     unordered_set<int>::iterator it = s.begin();
  
        advance(it,rand()%(s.size()));
        int x = *it;
        return x;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
