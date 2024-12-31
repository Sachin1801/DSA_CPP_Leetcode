class MyQueue {
    private:
        stack<int>s1;
        stack<int> s2;
        
public:
    MyQueue() {
        stack<int> *s1 = new stack<int>;
        stack<int> *s2 = new stack<int>;
    }
    
    void push(int x) {
        if(s1.size()==0) s1.push(x);
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    int pop() {
        int top = s1.top();
        if(!s1.empty()){
            s1.pop();
        }
        return top;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.size()==0;
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