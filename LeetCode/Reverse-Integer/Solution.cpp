1class Solution {
2public:
3    int reverse(int x) {
4        long long  fd = 0;
5        while(x != 0){
6            int  ld = x % 10;
7            fd = (fd * 10 ) + ld;
8            x = x / 10;
9        }
10        if( fd  < INT_MIN || fd > INT_MAX) return 0;
11        return (int)fd ;
12    }
13};