class MinStack {
public:
    vector<pair<long,long>> stack;
    MinStack() {
        
    }
    void push(int val) {

         if(stack.size()==0 or val< stack[stack.size()-1].second){
            stack.push_back({val,val});
        }
        else{
            stack.push_back({val,stack[stack.size()-1].second});
        }

    }
    
    void pop() {
        if(stack.size()>=1){
            stack.pop_back();
        }
    }
    
    int top() {
        return stack[stack.size()-1].first;
    }
    
    int getMin() {
        return stack[stack.size()-1].second;
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
