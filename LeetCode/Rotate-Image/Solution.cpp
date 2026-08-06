1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        int n = matrix.size();
5        for(int i = 0 ;i<=n-2;i++){
6            for(int j= i+1;j<=n-1;j++){
7                swap(matrix[i][j],matrix[j][i]);
8            }
9        }
10        for(int i = 0;i<=n-1;i++){
11            reverse(matrix[i].begin(),matrix[i].end());
12        }
13    }
14};