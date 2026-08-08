1class Solution {
2public:
3
4    int largestRectangleArea(vector<int> &heights) {
5        int n = heights.size();
6        stack<int> st;
7
8        int leftsmall[n], rightsmall[n];
9
10        // Compute Nearest Smaller to Left (NSL) for each bar
11        for (int i = 0; i < n; i++) {
12            // Pop until a smaller element is found or stack is empty
13            while (!st.empty() && heights[st.top()] >= heights[i]) {
14                st.pop();
15            }
16
17            // If stack is empty, no smaller element on the left
18            leftsmall[i] = st.empty() ? 0 : st.top() + 1;
19
20            // Push current index to stack
21            st.push(i);
22        }
23
24        // Clear stack to reuse for NSR
25        while (!st.empty()) st.pop();
26
27        // Compute Nearest Smaller to Right (NSR) for each bar
28        for (int i = n - 1; i >= 0; i--) {
29            while (!st.empty() && heights[st.top()] >= heights[i]) {
30                st.pop();
31            }
32
33            // If stack is empty, no smaller to the right
34            rightsmall[i] = st.empty() ? n - 1 : st.top() - 1;
35
36            st.push(i);
37        }
38
39        // Calculate max area using NSL and NSR
40        int maxA = 0;
41        for (int i = 0; i < n; i++) {
42            int width = rightsmall[i] - leftsmall[i] + 1;
43            maxA = max(maxA, heights[i] * width);
44        }
45
46        return maxA;
47    }
48    int maximalRectangle(vector<vector<char>>& matrix) {
49        if (matrix.empty()) return 0;
50        int maxArea = 0;
51        int m = matrix[0].size();
52        vector<int> height(m,0);
53         for (auto& row : matrix) {
54
55            // Update histogram based on current row
56            for (int i = 0; i < m; i++) {
57                if (row[i] == '1') height[i]++;
58                else height[i] = 0;
59            }
60
61            // Compute area for this histogram
62            maxArea = max(maxArea, largestRectangleArea(height));
63        }
64
65        return maxArea;   
66
67    }
68};