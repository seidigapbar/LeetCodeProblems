class MinStack {
private:
    stack<int> vals;
    stack<int> minimals;
public:
    MinStack() {

    }
    
    void push(int val) {
        vals.push(val);
        if(!minimals.empty()){
            minimals.push(min(this->getMin(), val));
        } else{
            minimals.push(val);
        }
    }
    
    void pop() {
        vals.pop();
        minimals.pop();
    }
    
    int top() {
        return vals.top();
    }
    
    int getMin() {
        return minimals.top();
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
