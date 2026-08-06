1class Solution {
2public:
3    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6
7        vector<vector<int>> ans(n, vector<int>(m));//we need to keep every row in one one col
8
9        for(int i=0;i<m;i++){
10            for(int j=0;j<n;j++){
11                ans[j][i]=matrix[i][j];
12            }
13        }
14        return ans;
15    }
16};