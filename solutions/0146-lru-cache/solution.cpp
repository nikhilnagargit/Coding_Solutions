class LRUCache {
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
        Node(int key,int val){
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };

public:
    int capacity;
    unordered_map<int,Node*>m;
    Node* dummy_head;
    Node* dummy_tail;
    LRUCache(int c) {
        capacity = c;
        dummy_head = new Node(-1,-1);
        dummy_tail = new Node(-1,-1);
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;    
    }
    
    void deletenode(Node* curr){
        Node* prevnode = curr->prev;
        Node* nextnode = curr->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }
    Node* createandinsertnode(int key,int val){
        Node* newnode = new Node(key,val);
        Node* temp1 = dummy_head->next;
        dummy_head->next = newnode;
        newnode->prev = dummy_head;
        newnode->next = temp1;
        temp1->prev = newnode;
        return newnode;
    }

    int get(int key) {
        // check if exist in map
        if(m.find(key)==m.end()){
            return -1;
        }
        // delete from list and map, and create new entery then return value
        int ans = m[key]->val;
        deletenode(m[key]);
        m.erase(key);
        m[key] = createandinsertnode(key,ans);
        return ans;
    }
    
    void put(int key, int value) {
        if(m.size()==capacity){
            if(m.find(key)==m.end()){
                // delete lru 
                int key_to_delete = dummy_tail->prev->key;
                deletenode(dummy_tail->prev);
                // delete from map
                m.erase(key_to_delete);
                m[key] = createandinsertnode(key,value);
            }
            else{
                // delete the exisitng
                deletenode(m[key]);
                m.erase(key);
                // add new
                m[key] = createandinsertnode(key,value);
            }
        }
        else{
            if(m.find(key)==m.end()){
                m[key] = createandinsertnode(key,value);
            }
            else{
                  // delete the exisitng
                deletenode(m[key]);
                m.erase(key);
                // add new
                m[key] = createandinsertnode(key,value);
            }
        }
    }
};
