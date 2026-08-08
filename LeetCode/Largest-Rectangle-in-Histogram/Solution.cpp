1class Solution {
2public:
3    int largestRectangleArea(vector<int>& heights) {
4        int n = heights.size();
5        stack<int> st;
6
7        int leftsmall[n], rightsmall[n];
8
9        // Compute Nearest Smaller to Left (NSL) for each bar
10        for (int i = 0; i < n; i++) {
11            // Pop until a smaller element is found or stack is empty
12            while (!st.empty() && heights[st.top()] >= heights[i]) {
13                st.pop();
14            }
15
16            // If stack is empty, no smaller element on the left
17            leftsmall[i] = st.empty() ? 0 : st.top() + 1;
18
19            // Push current index to stack
20            st.push(i);
21        }
22
23        // Clear stack to reuse for NSR
24        while (!st.empty()) st.pop();
25
26        // Compute Nearest Smaller to Right (NSR) for each bar
27        for (int i = n - 1; i >= 0; i--) {
28            while (!st.empty() && heights[st.top()] >= heights[i]) {
29                st.pop();
30            }
31
32            // If stack is empty, no smaller to the right
33            rightsmall[i] = st.empty() ? n - 1 : st.top() - 1;
34
35            st.push(i);
36        }
37
38        // Calculate max area using NSL and NSR
39        int maxA = 0;
40        for (int i = 0; i < n; i++) {
41            int width = rightsmall[i] - leftsmall[i] + 1;
42            maxA = max(maxA, heights[i] * width);
43        }
44
45        return maxA;
46    }
47};