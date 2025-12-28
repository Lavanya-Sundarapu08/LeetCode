1class Solution {
2public:
3    int countNegatives(vector<vector<int>>& grid) {
4    int m= grid.size();
5    int cnt =0;
6    int n = grid[0].size();
7     for(int i =0;i<m;i++){
8        for(int j=0;j<n;j++){
9            if(grid[i][j]<0){
10                cnt++;
11            }
12        }
13     }
14     return cnt;
15    }
16};