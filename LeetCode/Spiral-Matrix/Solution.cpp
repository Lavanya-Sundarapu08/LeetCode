1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6
7        int top = 0;
8        int bottom = m - 1;
9        int left = 0;
10        int right = n - 1;
11
12        vector<int> ans;
13
14        while (top <= bottom && left <= right) {
15
16            // Left -> Right
17            for (int j = left; j <= right; j++)
18                ans.push_back(matrix[top][j]);
19            top++;
20
21            // Top -> Bottom
22            for (int i = top; i <= bottom; i++)
23                ans.push_back(matrix[i][right]);
24            right--;
25
26            // Right -> Left
27            if (top <= bottom) {
28                for (int j = right; j >= left; j--)
29                    ans.push_back(matrix[bottom][j]);
30                bottom--;
31            }
32
33            // Bottom -> Top
34            if (left <= right) {
35                for (int i = bottom; i >= top; i--)
36                    ans.push_back(matrix[i][left]);
37                left++;
38            }
39        }
40
41        return ans;
42    }
43};