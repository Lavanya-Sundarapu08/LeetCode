1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5
6        for(char c : s){
7            if (c == '(' || c == '{' || c == '[') {
8                st.push(c);
9            }
10            else{
11                 if (st.empty()) {
12                    return false;
13                }
14
15                char top = st.top();
16                st.pop();
17
18                if ((c == ')' && top != '(') ||
19                    (c == '}' && top != '{') ||
20                    (c == ']' && top != '[')) {
21                    return false;
22                }
23            }
24
25        }
26        return st.empty();
27    }
28};