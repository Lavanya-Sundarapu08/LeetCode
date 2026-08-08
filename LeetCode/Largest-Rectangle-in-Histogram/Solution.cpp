1class Solution {
2public:
3    int largestRectangleArea(vector<int>& heights) {
4        stack<int> st;
5        int maxArea = 0;
6
7        int n = heights.size();
8
9        for(int i =0;i<=n;i++){
10
11            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
12                int heightA= heights[st.top()];
13                st.pop();
14
15                int width;
16                if(st.empty()){
17                    width = i;
18
19                }else{
20                    width = i - st.top() - 1;
21
22                }
23
24                maxArea = max(maxArea, width * heightA);
25            }
26            st.push(i);
27        }
28        return maxArea;
29
30    }
31};