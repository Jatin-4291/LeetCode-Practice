// Last updated: 8/23/2025, 2:38:43 PM
class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        vector<int> a;
        int ans=-1;
        while(!q.empty()){
            ans=q.front();
            a.push_back(q.front());
            q.pop();
        }
        for(int i=0;i<a.size()-1;i++){
            q.push(a[i]);
        }
        return ans;
    }
    
    int top() {
        vector<int> a;
        int ans=-1;
        while(!q.empty()){
            ans=q.front();
            a.push_back(q.front());
            q.pop();
        }
        for(int i=0;i<a.size();i++){
            q.push(a[i]);
        }
        return ans; 
    }
    
    bool empty() {
        if(q.size()>0){
            return false;
        }
        return true;
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