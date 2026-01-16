1class Solution {
2public:
3    int climbStairs(int n) {
4        if (n <= 2) return n;
5
6        int prev2 = 1, prev1 = 2;
7        for (int i = 3; i <= n; i++) {
8            int curr = prev1 + prev2;
9            prev2 = prev1;
10            prev1 = curr;
11        }
12        return prev1;
13    }
14};