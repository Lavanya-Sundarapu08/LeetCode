1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        int n = matrix.size(); // size of the rows
5        int m = matrix[0].size();//size of the colms [list inside list ]
6        vector<int> res;
7
8        int left = 0 ,right = m-1, top = 0, bottom = n-1;
9        while(left <= right && top <= bottom){
10            for(int i= left ; i<= right;i++){
11                res.push_back(matrix[top][i]);
12            }
13            top++;
14            for(int i= top;i<= bottom ;i++){
15                res.push_back(matrix[i][right]);
16            }
17            right--;
18            if(top<=bottom){
19                for(int i = right; i>= left;i--){
20                res.push_back(matrix[bottom][i]);
21            }
22            bottom--;
23            }
24            if(left<= right){
25                 for(int i= bottom;i>= top;i--){
26                res.push_back(matrix[i][left]);
27            }
28            left++;
29            }
30        }
31        return res;
32    }
33};