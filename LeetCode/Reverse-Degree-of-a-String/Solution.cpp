1class Solution {
2public:
3    int reverseDegree(string s) {
4        int ans = 0;
5
6        for(int i = 0; i < s.length() ; i++){
7            int res = 'z' - s[i] + 1;
8            ans += res * (i+1);
9        }
10        return ans;
11    }
12};