1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5    unordered_map<char, char> match = {
6        {')', '('},
7        {']', '['},
8        {'}', '{'}
9    };
10    
11    for (char c : s) {
12        // If it's an opening bracket, push to stack
13        if (c == '(' || c == '[' || c == '{') {
14            st.push(c);
15        } else {
16            // If it's a closing bracket
17            if (st.empty() || st.top() != match[c])
18                return false;
19            st.pop();
20        }
21    }
22    
23    return st.empty();
24    }
25};