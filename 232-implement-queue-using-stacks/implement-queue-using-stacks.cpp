class MyQueue {
public:
    stack<int> s;
    stack<int> f; 
    MyQueue() {
           
    }
    void push(int x) {
        s.push(x);    
    }
    
    int pop() {
        //if(s.empty()) return NULL;
        while(!(s.empty())){
            f.push(s.top());
            s.pop();
        }
        int x=f.top();
        f.pop();
        while(!(f.empty())){
            s.push(f.top());
            f.pop();
        }
        return x;
    }
    
    int peek() {
        if(s.empty()) return NULL;
        while(!(s.empty())){
            f.push(s.top());
            s.pop();
        }
        int x=f.top();
        while(!(f.empty())){
            s.push(f.top());
            f.pop();
        }
        return x;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */