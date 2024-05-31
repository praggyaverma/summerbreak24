class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    }
    
    void push(int x) { // TC - O(n)
        int n = q1.size(), t = q1.size();
        while (n--){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        for(int i = 0; i < t; i++){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() { // TC - O(1)
        int res = top();
        q1.pop();
        return res;
    }
    
    int top() { // TC - O(1)
        return q1.front();
    }
    
    bool empty() { // TC - O(1)
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
