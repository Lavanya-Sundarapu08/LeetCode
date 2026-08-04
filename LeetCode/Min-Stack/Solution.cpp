1class MinStack {
2public:
3
4    stack<long long> st;
5    long long mini;
6
7    MinStack() {
8    }
9    
10    void push(int value) {
11        if(st.empty()){
12            mini = value;
13            st.push(value);
14            return;
15        }
16        
17        if(value >= mini){
18            st.push(value);
19        }
20        else{
21            st.push(2LL * value - mini);
22            mini = value;
23        }
24    }
25    
26    void pop() {
27        if(st.empty()) return;
28
29        long long x = st.top();
30        st.pop();
31
32        if(x < mini){
33            mini = 2LL * mini - x;
34        }
35    }
36    
37    int top() {
38
39        if(st.empty()) return -1;
40
41        long long x = st.top();
42        if(x >= mini) return x;
43        else return mini;
44    }
45    
46    int getMin() {
47        return mini;
48    }
49};
50
51/**
52 * Your MinStack object will be instantiated and called as such:
53 * MinStack* obj = new MinStack();
54 * obj->push(value);
55 * obj->pop();
56 * int param_3 = obj->top();
57 * int param_4 = obj->getMin();
58 */