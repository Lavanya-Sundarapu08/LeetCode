1class Solution {
2public:
3    int trailingZeroes(int n) {
4        int count =0;
5
6        while(n >0){
7            n /= 5;
8            count = count+n;
9        }
10        return count;
11    }
12};