1class Solution {
2public:
3    int diagonalSum(vector<vector<int>>& mat) {
4        int n = mat.size();
5        int sum =0;
6
7        for(int i =0;i<n;i++){
8            sum += mat[i][i];
9            sum += mat[i][n-i-1];
10        }
11
12        if(n % 2 ==1){
13            sum -= mat[n/2][n/2];
14        }
15        return sum;
16    }
17};