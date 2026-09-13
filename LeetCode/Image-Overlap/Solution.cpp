1class Solution {
2public:
3    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
4        int n = img1.size();
5
6        vector<pair<int, int>> one1;
7        vector<pair<int, int>> one2;
8
9        for(int i = 0;i<n;i++){
10            for(int j = 0;j<n;j++){
11                if(img1[i][j] == 1)
12                    one1.push_back({i,j});
13                if(img2[i][j] == 1)
14                    one2.push_back({i,j});
15            }
16        }
17        unordered_map<string, int> freq;
18
19        int ans = 0;
20        for(auto [x1,y1] : one1){
21            for(auto [x2,y2]: one2){
22                int dx = x2- x1;
23                int dy = y2 - y1;
24
25                string key = to_string(dx)+ "," + to_string(dy);
26
27                freq[key]++;
28
29                ans = max(ans, freq[key]);
30            }
31        }
32        return ans;
33    }
34};