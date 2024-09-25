class MinStack {
public:
    vector<int> v,miniv;
    int mini;
    MinStack() {
        v={};
        mini = INT_MAX;
        miniv={};
    }
    
    void push(int val) {
        v.push_back(val);
        if(miniv.size()!=0)    mini = min(mini,val);
        else mini = val;
        miniv.push_back(mini);
    }
    
    void pop() {
        v.pop_back();
        miniv.pop_back();
        if(miniv.size()>0)    mini=miniv.back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return miniv.back();
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