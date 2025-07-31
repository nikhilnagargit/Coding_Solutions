
class Node{
    public:
    Node* next;
    Node* prev;
    int val;
    int key;
    Node(){
        key = 0;
        val = 0;
        next = nullptr;
        prev = nullptr;
    }
    Node(int k,int v){
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};


class LRUCache {
public:
    unordered_map<int,Node*> m;
    Node* head;
    Node* tail;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* curr = m[key];
            removeNode(curr);
            insertNodeAtHead(curr);
            m[key] = curr;
            return m[key]->val;
        }
        return -1;
    }

    void insertNodeAtHead(Node* new_node){
        Node* nxt = head->next;
        head->next = new_node;
        new_node->prev = head;
        new_node->next = nxt;
        nxt->prev = new_node;
    }

    void removeNode(Node* node){
        Node* prev = node->prev;
        Node* nxt = node->next;
        node->next = nullptr;
        node->prev = nullptr;
        prev->next = nxt;
        nxt->prev = prev;
    }
    
    void put(int key, int value) {
        Node* new_node = new Node(key,value);
        if(m.find(key)!=m.end()){
            removeNode(m[key]);
        }
        m[key] = new_node;
        insertNodeAtHead(new_node);
        if(m.size()>limit){
            // remove oldest means tail of the ll
            m.erase(tail->prev->key);
            removeNode(tail->prev);
        }

    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
