// Last updated: 8/23/2025, 2:38:38 PM
class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> x;
        int ans=-1;
        while(!st.empty()){
            ans=st.top();
            x.push(st.top());
            st.pop();
        }
        x.pop();
        while(!x.empty()){
            st.push(x.top());
            x.pop();
        }
        return ans;
    }
    
    int peek() {
       stack<int> x;
        int ans=-1;
        while(!st.empty()){
            ans=st.top();
            x.push(st.top());
            st.pop();
        }
        while(!x.empty()){
            st.push(x.top());
            x.pop();
        }
        return ans; 
    }
    
    bool empty() {
        if(st.size()>0){
            return false;
        }
        return true;
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