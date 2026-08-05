1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        
5        int n = nums.size();
6
7        vector<int> nge(n);
8
9        stack<int> st;
10
11        for(int i =2*n-1;i>=0;i--){
12            int idx = i%n;
13            int currElement = nums[idx];
14
15            while(!st.empty() && st.top() <= currElement){
16                st.pop();
17            }
18
19            if(i < n){
20                if(st.empty()) nge[i] = -1;
21                else nge[i] = st.top();
22            }
23
24            st.push(currElement);
25        }
26        return nge;
27    }
28};