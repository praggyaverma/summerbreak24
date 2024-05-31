class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) { // TC - O(N)
        int n = s1.size();
        for(int i = 0; i < n; i++){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        for(int i = 0; i < n; i++){
            s1.push(s2.top());
            s2.pop();
        } 
    }
    
    int pop() { // TC - O(1)
        int res = s1.top();
        s1.pop();
        return res;
    }
    
    int peek() { // TC - O(1)
        return s1.top();
    }
    
    bool empty() { // TC - O(1)
        return s1.empty();
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
