class MinStack {
public:
    vector<int> container;
    int size=0;
    vector<int> minimum;
    int min_size=0;
    MinStack() {
        container = vector<int>(30002,INT_MAX);
        minimum = vector<int>(300002,INT_MAX);
    }
    
    void push(int val) {
        container[size]=val;
        size++;
        if(min_size==0){
            minimum[0] = val;
            min_size++;
        }
        else if(val<=minimum[min_size-1]){
            minimum[min_size] = val;
            min_size++;
        }
    }
    
    void pop() {
        if(size>0){
            if(container[size-1]==minimum[min_size-1]){
                minimum[min_size-1]=INT_MAX;
                min_size--;
            }
            size--;
        }
    }
    
    int top() {
        return container[size-1];
    }
    
    int getMin() {
        return minimum[min_size-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
