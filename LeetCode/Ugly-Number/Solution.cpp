1class Solution {
2public:
3    bool isUgly(int n) {
4        if (n <= 0) return false;
5
6        while (n % 2 == 0)
7            n /= 2;
8
9        while (n % 3 == 0)
10            n /= 3;
11
12        while (n % 5 == 0)
13            n /= 5;
14
15        return n == 1;
16    }
17};